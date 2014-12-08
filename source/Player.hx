package;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.system.FlxSound;
import flixel.group.FlxGroup;
import flixel.util.FlxMath;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxTimer;

class Player extends FlxSprite
{

	var _maxSpeed:Int = 200;
	var _maxAcceleration:Int = 1000;
	var _drag:Int = 1000;
	var _gravity:Int = 1600;
	var _maxFallSpeed:Int = 800;
	var _jumpforce:Int = 420;

	public var _health:Int = 100;

	public var bullets:FlxGroup;
	var bullet:Bullet;
	var bulletDelay:Int;

	var _shootSound:FlxSound;

	public function new(x:Float, y:Float)
	{
		super(x, y);
		loadGraphic("assets/images/player.png", true, 32, 32);

		animation.add("idle", [0]);
		animation.add("walking", [0, 1, 2, 3, 4, 5, 6, 7], 13);
		animation.add("jumping", [8]);

		setFacingFlip(FlxObject.LEFT, true, false);
		setFacingFlip(FlxObject.RIGHT, false, false);

		_shootSound = FlxG.sound.load("assets/sounds/shoot.wav", 0.4);

		maxVelocity.y = _maxFallSpeed;
		acceleration.y = _gravity;
		drag.x = _drag;

		health = _health;

		bullets = new FlxGroup();

		bulletDelay = 5;
	}

	override public function update():Void
	{
		controls();
		animate();
		levelConstraints();

		super.update();
	}

	override public function kill():Void
	{
		alive = false;
		scale.set(1.5, 1.5);
		FlxTween.tween(scale, { x:1, y:1 }, 0.5, { ease:FlxEase.elasticOut, complete:finishKill });
		acceleration.y = 1200;
		velocity.y = -200;
		allowCollisions = FlxObject.NONE;
		new FlxTimer(1, Reg.state.gameOver);
	}

	function finishKill(_):Void
	{
		exists = false;
	}

	function controls():Void
	{
		var xForce:Float = 0;
		var jumping:Bool = false;

		if (FlxG.keys.pressed.LEFT) {
			xForce--;
			facing = FlxObject.LEFT;
		}

		if (FlxG.keys.pressed.RIGHT) {
			xForce++;
			facing = FlxObject.RIGHT;
		}

		if (FlxG.keys.justPressed.SPACE) jumping = true;
		if (FlxG.keys.justReleased.SPACE) velocity.y = velocity.y * 0.5;

		xForce = FlxMath.bound(xForce, -1, 1);

		maxVelocity.x = _maxSpeed;
		acceleration.x = xForce * _maxAcceleration;

		if (jumping && isTouching(FlxObject.FLOOR)) {
			var finalJumpForce:Float = -(_jumpforce + Math.abs(velocity.x * 0.25));
			velocity.y = finalJumpForce;
		}

		bulletDelay--;

		if (FlxG.keys.justPressed.A && bulletDelay < 0) {
			bulletDelay = 5;

			if (facing == FlxObject.LEFT) {
				bullet = new Bullet(x + width / 2 - 8, y + height / 2 - 2);
				bullet.velocity.x = -bullet._velocity;
				bullets.add(bullet);
			} else {
				bullet = new Bullet(x + width / 2 + 7, y + height / 2 - 2);
				bullets.add(bullet);
			}

			_shootSound.setPosition(x, y);
			_shootSound.play(true);
		}
	}

	function animate():Void
	{
		if (velocity.x == 0) animation.play("idle");
		else if(!isTouching(FlxObject.FLOOR)) animation.play("jumping");
		else animation.play("walking");
	}

	function levelConstraints():Void
	{
		if (x < 0 || x > Reg.state.level.width - width) velocity.x = 0;
	}

}