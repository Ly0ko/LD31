package;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;

class Bullet extends FlxSprite
{

	public var _velocity = 300;

	public function new(x:Float, y:Float)
	{
		super(x, y);

		makeGraphic(4, 2, 0xff00ffff);
		velocity.x = _velocity;
	} 

	override public function update():Void
	{
		levelConstraints();

		super.update();
	}

	function levelConstraints() {
		if (x < 0 || x > Reg.state.level.width - width) kill();
	}

}