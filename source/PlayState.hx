package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.FlxObject;
import flixel.FlxCamera;
import flixel.group.FlxGroup;
import flixel.tile.FlxTilemap;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;
import flixel.util.FlxStringUtil;
import flixel.util.FlxSpriteUtil;
import flixel.util.FlxTimer;
import openfl.Assets;

/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{

	public var level:FlxTilemap;
	public var player:Player;

	var healthText:FlxText;
	var killsText:FlxText;
	var kills:Int;

	var waves:FlxGroup;
	var mob:Mob;

	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		FlxG.camera.antialiasing = true;
		FlxG.camera.bgColor = 0xff545454;
		Reg.state = this;

		addLevel();
		addPlayer();
		addUIText();

		kills = 0;

		waves = new FlxGroup();

		new FlxTimer(2, addWave, 5);
		new FlxTimer(15, waveTimer, 0);

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
		FlxG.collide(level, waves);
		FlxG.collide(player.bullets, level, bulletHitMap);
		FlxG.collide(player.bullets, waves, bulletHitMob);
		FlxG.collide(waves, player, enemyPlayerOverlap);

		if (player.exists == false) {
			if (FlxG.keys.justPressed.ANY) restart();
		}

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

	function addWave(?_):Void
	{
		waves.add(new Mob(10, 550));
		waves.add(new Mob(780, 550));
		add(waves);
	}

	function waveTimer(_):Void
	{
		new FlxTimer(2, addWave, 6);
	}

	function addUIText():Void
	{
		healthText = new FlxText(0, 580, FlxG.width);
		healthText.scrollFactor.set();
		healthText.setFormat(null, 8, 0xdeeed6, "right", FlxText.BORDER_SHADOW, 0x4e4a4e);
		add(healthText);

		killsText = new FlxText(0, 580, FlxG.width);
		killsText.scrollFactor.set();
		killsText.setFormat(null, 8, 0xdeeed6, "center", FlxText.BORDER_SHADOW, 0x4e4a4e);
		add(killsText);
	}

	function setUIText():Void
	{
		healthText.text = "HEALTH: " + player.health;
		killsText.text = "KILLS: " + kills;
	}

	function enemyPlayerOverlap(mobRef:FlxObject, playerRef:FlxObject):Void
	{
		playerRef.health -= 0.5;

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

		if (mobRef.health <= 0) {
			kills++;
			mobRef.kill();
		}
	}

	public function gameOver(?t:FlxTimer):Void
	{
		var gameOverText:FlxText = new FlxText(0, 0, 0, "GAME OVER");
		var restartText:FlxText = new FlxText(0, 350, 0, "Press any key to restart.");

		gameOverText.scrollFactor.set(0, 0);
		FlxSpriteUtil.screenCenter(gameOverText);
		add(gameOverText);

		restartText.scrollFactor.set(0, 0);
		restartText.size = 8;
		FlxSpriteUtil.screenCenter(restartText, true, false);
		add(restartText);
	}

	function restart():Void 
	{
		FlxG.switchState(new PlayState());
	}
}