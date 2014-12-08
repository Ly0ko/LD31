#include <hxcpp.h>

#ifndef INCLUDED_Mob
#include <Mob.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_Reg
#include <Reg.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyList
#include <flixel/input/keyboard/FlxKeyList.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyboard
#include <flixel/input/keyboard/FlxKeyboard.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSpriteUtil
#include <flixel/util/FlxSpriteUtil.h>
#endif
#ifndef INCLUDED_flixel_util_FlxTimer
#include <flixel/util/FlxTimer.h>
#endif
#ifndef INCLUDED_openfl__v2_Assets
#include <openfl/_v2/Assets.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObjectContainer
#include <openfl/_v2/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_display_InteractiveObject
#include <openfl/_v2/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Sprite
#include <openfl/_v2/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif

Void PlayState_obj::__construct(Dynamic MaxSize)
{
HX_STACK_FRAME("PlayState","new",0xf8bf96cf,"PlayState.new","PlayState.hx",21,0xb30d7781)
HX_STACK_THIS(this)
HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(21)
	super::__construct(MaxSize);
}
;
	return null();
}

//PlayState_obj::~PlayState_obj() { }

Dynamic PlayState_obj::__CreateEmpty() { return  new PlayState_obj; }
hx::ObjectPtr< PlayState_obj > PlayState_obj::__new(Dynamic MaxSize)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(MaxSize);
	return result;}

Dynamic PlayState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PlayState_obj::create( ){
{
		HX_STACK_FRAME("PlayState","create",0x82220fed,"PlayState.create","PlayState.hx",38,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(39)
		::flixel::FlxG_obj::camera->set_antialiasing(true);
		HX_STACK_LINE(40)
		::flixel::FlxG_obj::camera->bgColor = (int)-11250604;
		HX_STACK_LINE(41)
		::Reg_obj::state = hx::ObjectPtr<OBJ_>(this);
		HX_STACK_LINE(43)
		this->addLevel();
		HX_STACK_LINE(44)
		this->addPlayer();
		HX_STACK_LINE(45)
		this->addUIText();
		HX_STACK_LINE(47)
		this->kills = (int)0;
		HX_STACK_LINE(49)
		::flixel::group::FlxGroup _g = ::flixel::group::FlxGroup_obj::__new(null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(49)
		this->waves = _g;
		HX_STACK_LINE(51)
		::flixel::util::FlxTimer_obj::__new((int)2,this->addWave_dyn(),(int)5);
		HX_STACK_LINE(52)
		::flixel::util::FlxTimer_obj::__new((int)15,this->waveTimer_dyn(),(int)0);
		HX_STACK_LINE(54)
		this->add(this->player->bullets);
		HX_STACK_LINE(56)
		this->super::create();
	}
return null();
}


Void PlayState_obj::destroy( ){
{
		HX_STACK_FRAME("PlayState","destroy",0x6ec756e9,"PlayState.destroy","PlayState.hx",65,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(65)
		this->super::destroy();
	}
return null();
}


Void PlayState_obj::update( ){
{
		HX_STACK_FRAME("PlayState","update",0x8d182efa,"PlayState.update","PlayState.hx",72,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(73)
		this->setUIText();
		HX_STACK_LINE(75)
		::flixel::FlxG_obj::overlap(this->level,this->player,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(76)
		::flixel::FlxG_obj::overlap(this->level,this->waves,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(77)
		::flixel::FlxG_obj::overlap(this->player->bullets,this->level,this->bulletHitMap_dyn(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(78)
		::flixel::FlxG_obj::overlap(this->player->bullets,this->waves,this->bulletHitMob_dyn(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(79)
		::flixel::FlxG_obj::overlap(this->waves,this->player,this->enemyPlayerOverlap_dyn(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(81)
		if (((this->player->exists == false))){
			HX_STACK_LINE(82)
			if ((::flixel::FlxG_obj::keys->justPressed->get_ANY())){
				HX_STACK_LINE(82)
				this->restart();
			}
		}
		HX_STACK_LINE(85)
		this->super::update();
	}
return null();
}


Void PlayState_obj::addLevel( ){
{
		HX_STACK_FRAME("PlayState","addLevel",0x9a83c2d4,"PlayState.addLevel","PlayState.hx",89,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(90)
		::flixel::tile::FlxTilemap _g = ::flixel::tile::FlxTilemap_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(90)
		this->level = _g;
		HX_STACK_LINE(91)
		::String _g1 = ::openfl::_v2::Assets_obj::getText(HX_CSTRING("assets/data/map.csv"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(91)
		this->level->loadMap(_g1,HX_CSTRING("assets/images/mapTiles.png"),(int)16,(int)16,null(),null(),null(),null());
		HX_STACK_LINE(92)
		this->add(this->level);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,addLevel,(void))

Void PlayState_obj::addPlayer( ){
{
		HX_STACK_FRAME("PlayState","addPlayer",0x2c2fe411,"PlayState.addPlayer","PlayState.hx",96,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(97)
		::Player _g = ::Player_obj::__new((::flixel::FlxG_obj::width * 0.5),(int)520);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(97)
		this->player = _g;
		HX_STACK_LINE(98)
		this->add(this->player);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,addPlayer,(void))

Void PlayState_obj::addWave( ::flixel::util::FlxTimer _){
{
		HX_STACK_FRAME("PlayState","addWave",0xd570d269,"PlayState.addWave","PlayState.hx",102,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_,"_")
		HX_STACK_LINE(103)
		::Mob _g = ::Mob_obj::__new((int)10,(int)550);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(103)
		this->waves->add(_g);
		HX_STACK_LINE(104)
		::Mob _g1 = ::Mob_obj::__new((int)780,(int)550);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(104)
		this->waves->add(_g1);
		HX_STACK_LINE(105)
		this->add(this->waves);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlayState_obj,addWave,(void))

Void PlayState_obj::waveTimer( ::flixel::util::FlxTimer _){
{
		HX_STACK_FRAME("PlayState","waveTimer",0x26fb2efb,"PlayState.waveTimer","PlayState.hx",110,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_,"_")
		HX_STACK_LINE(110)
		::flixel::util::FlxTimer_obj::__new((int)2,this->addWave_dyn(),(int)6);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlayState_obj,waveTimer,(void))

Void PlayState_obj::addUIText( ){
{
		HX_STACK_FRAME("PlayState","addUIText",0xfc4b81b1,"PlayState.addUIText","PlayState.hx",114,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(115)
		::flixel::text::FlxText _g = ::flixel::text::FlxText_obj::__new((int)0,(int)580,::flixel::FlxG_obj::width,null(),null(),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(115)
		this->healthText = _g;
		HX_STACK_LINE(116)
		this->healthText->scrollFactor->set(null(),null());
		HX_STACK_LINE(117)
		this->healthText->setFormat(null(),(int)8,(int)14610134,HX_CSTRING("right"),(int)1,(int)5130830,null());
		HX_STACK_LINE(118)
		this->add(this->healthText);
		HX_STACK_LINE(120)
		::flixel::text::FlxText _g1 = ::flixel::text::FlxText_obj::__new((int)0,(int)580,::flixel::FlxG_obj::width,null(),null(),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(120)
		this->killsText = _g1;
		HX_STACK_LINE(121)
		this->killsText->scrollFactor->set(null(),null());
		HX_STACK_LINE(122)
		this->killsText->setFormat(null(),(int)8,(int)14610134,HX_CSTRING("center"),(int)1,(int)5130830,null());
		HX_STACK_LINE(123)
		this->add(this->killsText);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,addUIText,(void))

Void PlayState_obj::setUIText( ){
{
		HX_STACK_FRAME("PlayState","setUIText",0xa3cec1f2,"PlayState.setUIText","PlayState.hx",127,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(128)
		this->healthText->set_text((HX_CSTRING("HEALTH: ") + this->player->health));
		HX_STACK_LINE(129)
		this->killsText->set_text((HX_CSTRING("KILLS: ") + this->kills));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,setUIText,(void))

Void PlayState_obj::enemyPlayerOverlap( ::flixel::FlxObject mobRef,::flixel::FlxObject playerRef){
{
		HX_STACK_FRAME("PlayState","enemyPlayerOverlap",0xcd5f5d2f,"PlayState.enemyPlayerOverlap","PlayState.hx",133,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(mobRef,"mobRef")
		HX_STACK_ARG(playerRef,"playerRef")
		HX_STACK_LINE(134)
		hx::SubEq(playerRef->health,0.5);
		HX_STACK_LINE(136)
		if (((playerRef->health <= (int)0))){
			HX_STACK_LINE(136)
			playerRef->kill();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,enemyPlayerOverlap,(void))

Void PlayState_obj::bulletHitMap( ::flixel::FlxObject bulletRef,::flixel::FlxObject mapRef){
{
		HX_STACK_FRAME("PlayState","bulletHitMap",0x3db4899c,"PlayState.bulletHitMap","PlayState.hx",141,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(bulletRef,"bulletRef")
		HX_STACK_ARG(mapRef,"mapRef")
		HX_STACK_LINE(141)
		this->player->bullets->remove(bulletRef,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,bulletHitMap,(void))

Void PlayState_obj::bulletHitMob( ::flixel::FlxObject bulletRef,::flixel::FlxObject mobRef){
{
		HX_STACK_FRAME("PlayState","bulletHitMob",0x3db495c0,"PlayState.bulletHitMob","PlayState.hx",145,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(bulletRef,"bulletRef")
		HX_STACK_ARG(mobRef,"mobRef")
		HX_STACK_LINE(146)
		this->player->bullets->remove(bulletRef,null());
		HX_STACK_LINE(147)
		hx::SubEq(mobRef->health,(int)20);
		HX_STACK_LINE(149)
		if (((mobRef->health <= (int)0))){
			HX_STACK_LINE(150)
			(this->kills)++;
			HX_STACK_LINE(151)
			mobRef->kill();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,bulletHitMob,(void))

Void PlayState_obj::gameOver( ::flixel::util::FlxTimer t){
{
		HX_STACK_FRAME("PlayState","gameOver",0x64a21997,"PlayState.gameOver","PlayState.hx",156,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(t,"t")
		HX_STACK_LINE(157)
		::flixel::text::FlxText gameOverText = ::flixel::text::FlxText_obj::__new((int)0,(int)0,(int)0,HX_CSTRING("GAME OVER"),null(),null());		HX_STACK_VAR(gameOverText,"gameOverText");
		HX_STACK_LINE(158)
		::flixel::text::FlxText restartText = ::flixel::text::FlxText_obj::__new((int)0,(int)350,(int)0,HX_CSTRING("Press any key to restart."),null(),null());		HX_STACK_VAR(restartText,"restartText");
		HX_STACK_LINE(160)
		gameOverText->scrollFactor->set((int)0,(int)0);
		HX_STACK_LINE(161)
		::flixel::util::FlxSpriteUtil_obj::screenCenter(gameOverText,null(),null());
		HX_STACK_LINE(162)
		this->add(gameOverText);
		HX_STACK_LINE(164)
		restartText->scrollFactor->set((int)0,(int)0);
		HX_STACK_LINE(165)
		restartText->set_size((int)8);
		HX_STACK_LINE(166)
		::flixel::util::FlxSpriteUtil_obj::screenCenter(restartText,true,false);
		HX_STACK_LINE(167)
		this->add(restartText);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlayState_obj,gameOver,(void))

Void PlayState_obj::restart( ){
{
		HX_STACK_FRAME("PlayState","restart",0xb4e6f1be,"PlayState.restart","PlayState.hx",172,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(172)
		::flixel::FlxState State = ::PlayState_obj::__new(null());		HX_STACK_VAR(State,"State");
		HX_STACK_LINE(172)
		::flixel::FlxG_obj::game->_requestedState = State;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,restart,(void))


PlayState_obj::PlayState_obj()
{
}

void PlayState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlayState);
	HX_MARK_MEMBER_NAME(level,"level");
	HX_MARK_MEMBER_NAME(player,"player");
	HX_MARK_MEMBER_NAME(healthText,"healthText");
	HX_MARK_MEMBER_NAME(killsText,"killsText");
	HX_MARK_MEMBER_NAME(kills,"kills");
	HX_MARK_MEMBER_NAME(waves,"waves");
	HX_MARK_MEMBER_NAME(mob,"mob");
	::flixel::FlxState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PlayState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(level,"level");
	HX_VISIT_MEMBER_NAME(player,"player");
	HX_VISIT_MEMBER_NAME(healthText,"healthText");
	HX_VISIT_MEMBER_NAME(killsText,"killsText");
	HX_VISIT_MEMBER_NAME(kills,"kills");
	HX_VISIT_MEMBER_NAME(waves,"waves");
	HX_VISIT_MEMBER_NAME(mob,"mob");
	::flixel::FlxState_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PlayState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"mob") ) { return mob; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"level") ) { return level; }
		if (HX_FIELD_EQ(inName,"kills") ) { return kills; }
		if (HX_FIELD_EQ(inName,"waves") ) { return waves; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"player") ) { return player; }
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"addWave") ) { return addWave_dyn(); }
		if (HX_FIELD_EQ(inName,"restart") ) { return restart_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"addLevel") ) { return addLevel_dyn(); }
		if (HX_FIELD_EQ(inName,"gameOver") ) { return gameOver_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"killsText") ) { return killsText; }
		if (HX_FIELD_EQ(inName,"addPlayer") ) { return addPlayer_dyn(); }
		if (HX_FIELD_EQ(inName,"waveTimer") ) { return waveTimer_dyn(); }
		if (HX_FIELD_EQ(inName,"addUIText") ) { return addUIText_dyn(); }
		if (HX_FIELD_EQ(inName,"setUIText") ) { return setUIText_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"healthText") ) { return healthText; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"bulletHitMap") ) { return bulletHitMap_dyn(); }
		if (HX_FIELD_EQ(inName,"bulletHitMob") ) { return bulletHitMob_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"enemyPlayerOverlap") ) { return enemyPlayerOverlap_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PlayState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"mob") ) { mob=inValue.Cast< ::Mob >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"level") ) { level=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"kills") ) { kills=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"waves") ) { waves=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"player") ) { player=inValue.Cast< ::Player >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"killsText") ) { killsText=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"healthText") ) { healthText=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PlayState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("level"));
	outFields->push(HX_CSTRING("player"));
	outFields->push(HX_CSTRING("healthText"));
	outFields->push(HX_CSTRING("killsText"));
	outFields->push(HX_CSTRING("kills"));
	outFields->push(HX_CSTRING("waves"));
	outFields->push(HX_CSTRING("mob"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,level),HX_CSTRING("level")},
	{hx::fsObject /*::Player*/ ,(int)offsetof(PlayState_obj,player),HX_CSTRING("player")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(PlayState_obj,healthText),HX_CSTRING("healthText")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(PlayState_obj,killsText),HX_CSTRING("killsText")},
	{hx::fsInt,(int)offsetof(PlayState_obj,kills),HX_CSTRING("kills")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(PlayState_obj,waves),HX_CSTRING("waves")},
	{hx::fsObject /*::Mob*/ ,(int)offsetof(PlayState_obj,mob),HX_CSTRING("mob")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("level"),
	HX_CSTRING("player"),
	HX_CSTRING("healthText"),
	HX_CSTRING("killsText"),
	HX_CSTRING("kills"),
	HX_CSTRING("waves"),
	HX_CSTRING("mob"),
	HX_CSTRING("create"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("addLevel"),
	HX_CSTRING("addPlayer"),
	HX_CSTRING("addWave"),
	HX_CSTRING("waveTimer"),
	HX_CSTRING("addUIText"),
	HX_CSTRING("setUIText"),
	HX_CSTRING("enemyPlayerOverlap"),
	HX_CSTRING("bulletHitMap"),
	HX_CSTRING("bulletHitMob"),
	HX_CSTRING("gameOver"),
	HX_CSTRING("restart"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#endif

Class PlayState_obj::__mClass;

void PlayState_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("PlayState"), hx::TCanCast< PlayState_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void PlayState_obj::__boot()
{
}

