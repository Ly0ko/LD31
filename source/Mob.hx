package;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;

class Mob extends FlxSprite
{

	var maxSpeed = 50;
	var _gravity:Int = 1600;
	var _maxFallSpeed:Int = 800;

	public var _health:Int = 140;

	public function new(x:Float, y:Float)
	{
		super(x, y);

		makeGraphic(16, 20, 0xffff0000);
		health = _health;
		velocity.x = maxSpeed;
		maxVelocity.y = _maxFallSpeed;
		acceleration.y = _gravity;
	}

	override public function update():Void
	{
		(Reg.state.player.x < x) ? velocity.x = -maxSpeed : velocity.x = maxSpeed;

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
	}

	function finishKill(_):Void
	{
		exists = false;
	}
}