package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.FlxObject;
import flixel.tile.FlxTilemap;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;
import flixel.util.FlxStringUtil;
import openfl.Assets;

/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{

	public var level:FlxTilemap;
	public var player:Player;
	var healthText:FlxText;
	var mob:Mob;
	var mob2:Mob;

	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		FlxG.camera.bgColor = 0xff545454;
		Reg.state = this;

		addLevel();
		addPlayer();
		addUIText();

		mob = new Mob(120, 520);
		mob2 = new Mob(580, 520);
		add(mob);
		add(mob2);

		add(player.bullets);

		super.create();
	}
	
	/**
	 * Function that is called when this state is destroyed - you might want to 
	 * consider setting all objects this state uses to null to help garbage collection.
	 */
	override public function destroy():Void
	{
		super.destroy();
	}

	/**
	 * Function that is called once every frame.
	 */
	override public function update():Void
	{
		setUIText();

		FlxG.collide(level, player);
		FlxG.collide(level, mob);
		FlxG.collide(level, mob2);
		FlxG.collide(player.bullets, level, bulletHitMap);
		FlxG.collide(player.bullets, mob, bulletHitMob);
		FlxG.collide(player.bullets, mob2, bulletHitMob);
		FlxG.collide(mob, player, enemyPlayerOverlap);
		FlxG.collide(mob2, player, enemyPlayerOverlap);

		super.update();
	}	

	function addLevel():Void
	{
		level = new FlxTilemap();
		level.loadMap(Assets.getText("assets/data/map.csv"), "assets/images/mapTiles.png", 16, 16);
		add(level);
	}

	function addPlayer():Void
	{
		player = new Player(FlxG.width * 0.5, 520);
		add(player);
	}

	function addUIText():Void
	{
		healthText = new FlxText(0, 580, FlxG.width);
		healthText.scrollFactor.set();
		healthText.setFormat(null, 8, 0xdeeed6, "right", FlxText.BORDER_SHADOW, 0x4e4a4e);
		add(healthText);
	}

	function setUIText():Void
	{
		healthText.text = "HEALTH: " + player.health;
	}

	function enemyPlayerOverlap(mobRef:FlxObject, playerRef:FlxObject):Void
	{
		playerRef.health -= 1;

		if (playerRef.health <= 0) playerRef.kill();
	}

	function bulletHitMap(bulletRef:FlxObject, mapRef:FlxObject):Void
	{
		player.bullets.remove(bulletRef);
	}

	function bulletHitMob(bulletRef:FlxObject, mobRef:FlxObject):Void
	{
		player.bullets.remove(bulletRef);
		mobRef.health -= 20;

		if (mobRef.health <= 0) mobRef.kill();
	}
}