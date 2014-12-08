#include <hxcpp.h>

#ifndef INCLUDED_Bullet
#include <Bullet.h>
#endif
#ifndef INCLUDED_IMap
#include <IMap.h>
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
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
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
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
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
#ifndef INCLUDED_flixel_system_FlxSound
#include <flixel/system/FlxSound.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_SoundFrontEnd
#include <flixel/system/frontEnds/SoundFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxEase
#include <flixel/tweens/FlxEase.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_VarTween
#include <flixel/tweens/misc/VarTween.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxTimer
#include <flixel/util/FlxTimer.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif

Void Player_obj::__construct(Float x,Float y)
{
HX_STACK_FRAME("Player","new",0x8d5554f3,"Player.new","Player.hx",13,0xa27fc9dd)
HX_STACK_THIS(this)
HX_STACK_ARG(x,"x")
HX_STACK_ARG(y,"y")
{
	HX_STACK_LINE(23)
	this->_health = (int)100;
	HX_STACK_LINE(21)
	this->_jumpforce = (int)420;
	HX_STACK_LINE(20)
	this->_maxFallSpeed = (int)800;
	HX_STACK_LINE(19)
	this->_gravity = (int)1600;
	HX_STACK_LINE(18)
	this->_drag = (int)1000;
	HX_STACK_LINE(17)
	this->_maxAcceleration = (int)1000;
	HX_STACK_LINE(16)
	this->_maxSpeed = (int)200;
	HX_STACK_LINE(33)
	super::__construct(x,y,null());
	HX_STACK_LINE(34)
	this->loadGraphic(HX_CSTRING("assets/images/player.png"),true,(int)32,(int)32,null(),null());
	HX_STACK_LINE(36)
	this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add((int)0),null(),null());
	HX_STACK_LINE(37)
	this->animation->add(HX_CSTRING("walking"),Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)3).Add((int)4).Add((int)5).Add((int)6).Add((int)7),(int)13,null());
	HX_STACK_LINE(38)
	this->animation->add(HX_CSTRING("jumping"),Array_obj< int >::__new().Add((int)8),null(),null());
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",40,0xa27fc9dd)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , true,false);
				__result->Add(HX_CSTRING("y") , false,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(40)
	this->_facingFlip->set((int)1,_Function_1_1::Block());
	struct _Function_1_2{
		inline static Dynamic Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",41,0xa27fc9dd)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , false,false);
				__result->Add(HX_CSTRING("y") , false,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(41)
	this->_facingFlip->set((int)16,_Function_1_2::Block());
	HX_STACK_LINE(43)
	::flixel::system::FlxSound _g = ::flixel::FlxG_obj::sound->load(HX_CSTRING("assets/sounds/shoot.wav"),0.4,null(),null(),null(),null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(43)
	this->_shootSound = _g;
	HX_STACK_LINE(45)
	this->maxVelocity->set_y(this->_maxFallSpeed);
	HX_STACK_LINE(46)
	this->acceleration->set_y(this->_gravity);
	HX_STACK_LINE(47)
	this->drag->set_x(this->_drag);
	HX_STACK_LINE(49)
	this->health = this->_health;
	HX_STACK_LINE(51)
	::flixel::group::FlxGroup _g1 = ::flixel::group::FlxGroup_obj::__new(null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(51)
	this->bullets = _g1;
	HX_STACK_LINE(53)
	this->bulletDelay = (int)5;
}
;
	return null();
}

//Player_obj::~Player_obj() { }

Dynamic Player_obj::__CreateEmpty() { return  new Player_obj; }
hx::ObjectPtr< Player_obj > Player_obj::__new(Float x,Float y)
{  hx::ObjectPtr< Player_obj > result = new Player_obj();
	result->__construct(x,y);
	return result;}

Dynamic Player_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Player_obj > result = new Player_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Player_obj::update( ){
{
		HX_STACK_FRAME("Player","update",0xf1f8df56,"Player.update","Player.hx",57,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(58)
		this->controls();
		HX_STACK_LINE(59)
		this->animate();
		HX_STACK_LINE(60)
		this->levelConstraints();
		HX_STACK_LINE(62)
		this->super::update();
	}
return null();
}


Void Player_obj::kill( ){
{
		HX_STACK_FRAME("Player","kill",0x1b5c5bab,"Player.kill","Player.hx",66,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(67)
		this->set_alive(false);
		HX_STACK_LINE(68)
		this->scale->set(1.5,1.5);
		struct _Function_1_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",69,0xa27fc9dd)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("x") , (int)1,false);
					__result->Add(HX_CSTRING("y") , (int)1,false);
					return __result;
				}
				return null();
			}
		};
		struct _Function_1_2{
			inline static Dynamic Block( hx::ObjectPtr< ::Player_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",69,0xa27fc9dd)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("ease") , ::flixel::tweens::FlxEase_obj::elasticOut_dyn(),false);
					__result->Add(HX_CSTRING("complete") , __this->finishKill_dyn(),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(69)
		::flixel::tweens::FlxTween_obj::tween(this->scale,_Function_1_1::Block(),0.5,_Function_1_2::Block(this));
		HX_STACK_LINE(70)
		this->acceleration->set_y((int)1200);
		HX_STACK_LINE(71)
		this->velocity->set_y((int)-200);
		HX_STACK_LINE(72)
		this->allowCollisions = (int)0;
		HX_STACK_LINE(73)
		::flixel::util::FlxTimer_obj::__new((int)1,::Reg_obj::state->gameOver_dyn(),null());
	}
return null();
}


Void Player_obj::finishKill( ::flixel::tweens::FlxTween _){
{
		HX_STACK_FRAME("Player","finishKill",0x3332f55e,"Player.finishKill","Player.hx",78,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_,"_")
		HX_STACK_LINE(78)
		this->set_exists(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Player_obj,finishKill,(void))

Void Player_obj::controls( ){
{
		HX_STACK_FRAME("Player","controls",0xc9328d03,"Player.controls","Player.hx",82,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(83)
		Float xForce = (int)0;		HX_STACK_VAR(xForce,"xForce");
		HX_STACK_LINE(84)
		bool jumping = false;		HX_STACK_VAR(jumping,"jumping");
		HX_STACK_LINE(86)
		if ((::flixel::FlxG_obj::keys->checkStatus((int)37,::flixel::FlxG_obj::keys->pressed->checkStatus))){
			HX_STACK_LINE(87)
			(xForce)--;
			HX_STACK_LINE(88)
			this->set_facing((int)1);
		}
		HX_STACK_LINE(91)
		if ((::flixel::FlxG_obj::keys->checkStatus((int)39,::flixel::FlxG_obj::keys->pressed->checkStatus))){
			HX_STACK_LINE(92)
			(xForce)++;
			HX_STACK_LINE(93)
			this->set_facing((int)16);
		}
		HX_STACK_LINE(96)
		if ((::flixel::FlxG_obj::keys->checkStatus((int)32,::flixel::FlxG_obj::keys->justPressed->checkStatus))){
			HX_STACK_LINE(96)
			jumping = true;
		}
		HX_STACK_LINE(97)
		if ((::flixel::FlxG_obj::keys->checkStatus((int)32,::flixel::FlxG_obj::keys->justReleased->checkStatus))){
			HX_STACK_LINE(97)
			this->velocity->set_y((this->velocity->y * 0.5));
		}
		HX_STACK_LINE(99)
		{
			HX_STACK_LINE(99)
			Float lowerBound;		HX_STACK_VAR(lowerBound,"lowerBound");
			HX_STACK_LINE(99)
			if (((xForce < (int)-1))){
				HX_STACK_LINE(99)
				lowerBound = (int)-1;
			}
			else{
				HX_STACK_LINE(99)
				lowerBound = xForce;
			}
			HX_STACK_LINE(99)
			if (((lowerBound > (int)1))){
				HX_STACK_LINE(99)
				xForce = (int)1;
			}
			else{
				HX_STACK_LINE(99)
				xForce = lowerBound;
			}
		}
		HX_STACK_LINE(101)
		this->maxVelocity->set_x(this->_maxSpeed);
		HX_STACK_LINE(102)
		this->acceleration->set_x((xForce * this->_maxAcceleration));
		HX_STACK_LINE(104)
		if (((bool(jumping) && bool((((int(this->touching) & int((int)4096))) > (int)0))))){
			HX_STACK_LINE(105)
			Float _g = ::Math_obj::abs((this->velocity->x * 0.25));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(105)
			Float finalJumpForce = -(((this->_jumpforce + _g)));		HX_STACK_VAR(finalJumpForce,"finalJumpForce");
			HX_STACK_LINE(106)
			this->velocity->set_y(finalJumpForce);
		}
		HX_STACK_LINE(109)
		(this->bulletDelay)--;
		HX_STACK_LINE(111)
		if (((  ((::flixel::FlxG_obj::keys->checkStatus((int)65,::flixel::FlxG_obj::keys->justPressed->checkStatus))) ? bool((this->bulletDelay < (int)0)) : bool(false) ))){
			HX_STACK_LINE(112)
			this->bulletDelay = (int)5;
			HX_STACK_LINE(114)
			if (((this->facing == (int)1))){
				HX_STACK_LINE(115)
				Float _g1 = this->get_width();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(115)
				Float _g2 = (Float(_g1) / Float((int)2));		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(115)
				Float _g3 = (this->x + _g2);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(115)
				Float _g4 = (_g3 - (int)8);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(115)
				Float _g5 = this->get_height();		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(115)
				Float _g6 = (Float(_g5) / Float((int)2));		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(115)
				Float _g7 = (this->y + _g6);		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(115)
				Float _g8 = (_g7 - (int)2);		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(115)
				::Bullet _g9 = ::Bullet_obj::__new(_g4,_g8);		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(115)
				this->bullet = _g9;
				HX_STACK_LINE(116)
				this->bullet->velocity->set_x(-(this->bullet->_velocity));
				HX_STACK_LINE(117)
				this->bullets->add(this->bullet);
			}
			else{
				HX_STACK_LINE(119)
				Float _g10 = this->get_width();		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(119)
				Float _g11 = (Float(_g10) / Float((int)2));		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(119)
				Float _g12 = (this->x + _g11);		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(119)
				Float _g13 = (_g12 + (int)7);		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(119)
				Float _g14 = this->get_height();		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(119)
				Float _g15 = (Float(_g14) / Float((int)2));		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(119)
				Float _g16 = (this->y + _g15);		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(119)
				Float _g17 = (_g16 - (int)2);		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(119)
				::Bullet _g18 = ::Bullet_obj::__new(_g13,_g17);		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(119)
				this->bullet = _g18;
				HX_STACK_LINE(120)
				this->bullets->add(this->bullet);
			}
			HX_STACK_LINE(123)
			{
				HX_STACK_LINE(123)
				::flixel::system::FlxSound _this = this->_shootSound;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(123)
				_this->x = this->x;
				HX_STACK_LINE(123)
				_this->y = this->y;
			}
			HX_STACK_LINE(124)
			this->_shootSound->play(true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,controls,(void))

Void Player_obj::animate( ){
{
		HX_STACK_FRAME("Player","animate",0xa447a4b4,"Player.animate","Player.hx",130,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(130)
		if (((this->velocity->x == (int)0))){
			HX_STACK_LINE(130)
			this->animation->play(HX_CSTRING("idle"),null(),null());
		}
		else{
			HX_STACK_LINE(131)
			if ((!(((((int(this->touching) & int((int)4096))) > (int)0))))){
				HX_STACK_LINE(131)
				this->animation->play(HX_CSTRING("jumping"),null(),null());
			}
			else{
				HX_STACK_LINE(132)
				this->animation->play(HX_CSTRING("walking"),null(),null());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,animate,(void))

Void Player_obj::levelConstraints( ){
{
		HX_STACK_FRAME("Player","levelConstraints",0x97f955df,"Player.levelConstraints","Player.hx",137,0xa27fc9dd)
		HX_STACK_THIS(this)
		struct _Function_1_1{
			inline static bool Block( hx::ObjectPtr< ::Player_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",137,0xa27fc9dd)
				{
					HX_STACK_LINE(137)
					Float _g = ::Reg_obj::state->level->get_width();		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(137)
					Float _g1 = __this->get_width();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(137)
					Float _g2 = (_g - _g1);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(137)
					return (__this->x > _g2);
				}
				return null();
			}
		};
		HX_STACK_LINE(137)
		if (((  ((!(((this->x < (int)0))))) ? bool(_Function_1_1::Block(this)) : bool(true) ))){
			HX_STACK_LINE(137)
			this->velocity->set_x((int)0);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,levelConstraints,(void))


Player_obj::Player_obj()
{
}

void Player_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Player);
	HX_MARK_MEMBER_NAME(_maxSpeed,"_maxSpeed");
	HX_MARK_MEMBER_NAME(_maxAcceleration,"_maxAcceleration");
	HX_MARK_MEMBER_NAME(_drag,"_drag");
	HX_MARK_MEMBER_NAME(_gravity,"_gravity");
	HX_MARK_MEMBER_NAME(_maxFallSpeed,"_maxFallSpeed");
	HX_MARK_MEMBER_NAME(_jumpforce,"_jumpforce");
	HX_MARK_MEMBER_NAME(_health,"_health");
	HX_MARK_MEMBER_NAME(bullets,"bullets");
	HX_MARK_MEMBER_NAME(bullet,"bullet");
	HX_MARK_MEMBER_NAME(bulletDelay,"bulletDelay");
	HX_MARK_MEMBER_NAME(_shootSound,"_shootSound");
	::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Player_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_maxSpeed,"_maxSpeed");
	HX_VISIT_MEMBER_NAME(_maxAcceleration,"_maxAcceleration");
	HX_VISIT_MEMBER_NAME(_drag,"_drag");
	HX_VISIT_MEMBER_NAME(_gravity,"_gravity");
	HX_VISIT_MEMBER_NAME(_maxFallSpeed,"_maxFallSpeed");
	HX_VISIT_MEMBER_NAME(_jumpforce,"_jumpforce");
	HX_VISIT_MEMBER_NAME(_health,"_health");
	HX_VISIT_MEMBER_NAME(bullets,"bullets");
	HX_VISIT_MEMBER_NAME(bullet,"bullet");
	HX_VISIT_MEMBER_NAME(bulletDelay,"bulletDelay");
	HX_VISIT_MEMBER_NAME(_shootSound,"_shootSound");
	::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Player_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_drag") ) { return _drag; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bullet") ) { return bullet; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_health") ) { return _health; }
		if (HX_FIELD_EQ(inName,"bullets") ) { return bullets; }
		if (HX_FIELD_EQ(inName,"animate") ) { return animate_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_gravity") ) { return _gravity; }
		if (HX_FIELD_EQ(inName,"controls") ) { return controls_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_maxSpeed") ) { return _maxSpeed; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_jumpforce") ) { return _jumpforce; }
		if (HX_FIELD_EQ(inName,"finishKill") ) { return finishKill_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bulletDelay") ) { return bulletDelay; }
		if (HX_FIELD_EQ(inName,"_shootSound") ) { return _shootSound; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_maxFallSpeed") ) { return _maxFallSpeed; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_maxAcceleration") ) { return _maxAcceleration; }
		if (HX_FIELD_EQ(inName,"levelConstraints") ) { return levelConstraints_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Player_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_drag") ) { _drag=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bullet") ) { bullet=inValue.Cast< ::Bullet >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_health") ) { _health=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bullets") ) { bullets=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_gravity") ) { _gravity=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_maxSpeed") ) { _maxSpeed=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_jumpforce") ) { _jumpforce=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bulletDelay") ) { bulletDelay=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_shootSound") ) { _shootSound=inValue.Cast< ::flixel::system::FlxSound >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_maxFallSpeed") ) { _maxFallSpeed=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_maxAcceleration") ) { _maxAcceleration=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Player_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_maxSpeed"));
	outFields->push(HX_CSTRING("_maxAcceleration"));
	outFields->push(HX_CSTRING("_drag"));
	outFields->push(HX_CSTRING("_gravity"));
	outFields->push(HX_CSTRING("_maxFallSpeed"));
	outFields->push(HX_CSTRING("_jumpforce"));
	outFields->push(HX_CSTRING("_health"));
	outFields->push(HX_CSTRING("bullets"));
	outFields->push(HX_CSTRING("bullet"));
	outFields->push(HX_CSTRING("bulletDelay"));
	outFields->push(HX_CSTRING("_shootSound"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Player_obj,_maxSpeed),HX_CSTRING("_maxSpeed")},
	{hx::fsInt,(int)offsetof(Player_obj,_maxAcceleration),HX_CSTRING("_maxAcceleration")},
	{hx::fsInt,(int)offsetof(Player_obj,_drag),HX_CSTRING("_drag")},
	{hx::fsInt,(int)offsetof(Player_obj,_gravity),HX_CSTRING("_gravity")},
	{hx::fsInt,(int)offsetof(Player_obj,_maxFallSpeed),HX_CSTRING("_maxFallSpeed")},
	{hx::fsInt,(int)offsetof(Player_obj,_jumpforce),HX_CSTRING("_jumpforce")},
	{hx::fsInt,(int)offsetof(Player_obj,_health),HX_CSTRING("_health")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(Player_obj,bullets),HX_CSTRING("bullets")},
	{hx::fsObject /*::Bullet*/ ,(int)offsetof(Player_obj,bullet),HX_CSTRING("bullet")},
	{hx::fsInt,(int)offsetof(Player_obj,bulletDelay),HX_CSTRING("bulletDelay")},
	{hx::fsObject /*::flixel::system::FlxSound*/ ,(int)offsetof(Player_obj,_shootSound),HX_CSTRING("_shootSound")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_maxSpeed"),
	HX_CSTRING("_maxAcceleration"),
	HX_CSTRING("_drag"),
	HX_CSTRING("_gravity"),
	HX_CSTRING("_maxFallSpeed"),
	HX_CSTRING("_jumpforce"),
	HX_CSTRING("_health"),
	HX_CSTRING("bullets"),
	HX_CSTRING("bullet"),
	HX_CSTRING("bulletDelay"),
	HX_CSTRING("_shootSound"),
	HX_CSTRING("update"),
	HX_CSTRING("kill"),
	HX_CSTRING("finishKill"),
	HX_CSTRING("controls"),
	HX_CSTRING("animate"),
	HX_CSTRING("levelConstraints"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Player_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Player_obj::__mClass,"__mClass");
};

#endif

Class Player_obj::__mClass;

void Player_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Player"), hx::TCanCast< Player_obj> ,sStaticFields,sMemberFields,
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

void Player_obj::__boot()
{
}

