#include <hxcpp.h>

#ifndef INCLUDED_Bullet
#include <Bullet.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_Reg
#include <Reg.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
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
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif

Void Bullet_obj::__construct(Float x,Float y)
{
HX_STACK_FRAME("Bullet","new",0xf3208054,"Bullet.new","Bullet.hx",7,0xb42ce59c)
HX_STACK_THIS(this)
HX_STACK_ARG(x,"x")
HX_STACK_ARG(y,"y")
{
	HX_STACK_LINE(10)
	this->_velocity = (int)300;
	HX_STACK_LINE(14)
	super::__construct(x,y,null());
	HX_STACK_LINE(16)
	this->makeGraphic((int)4,(int)2,(int)-16711681,null(),null());
	HX_STACK_LINE(17)
	this->velocity->set_x(this->_velocity);
}
;
	return null();
}

//Bullet_obj::~Bullet_obj() { }

Dynamic Bullet_obj::__CreateEmpty() { return  new Bullet_obj; }
hx::ObjectPtr< Bullet_obj > Bullet_obj::__new(Float x,Float y)
{  hx::ObjectPtr< Bullet_obj > result = new Bullet_obj();
	result->__construct(x,y);
	return result;}

Dynamic Bullet_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bullet_obj > result = new Bullet_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Bullet_obj::update( ){
{
		HX_STACK_FRAME("Bullet","update",0xa9584695,"Bullet.update","Bullet.hx",21,0xb42ce59c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(22)
		this->levelConstraints();
		HX_STACK_LINE(24)
		this->super::update();
	}
return null();
}


Void Bullet_obj::levelConstraints( ){
{
		HX_STACK_FRAME("Bullet","levelConstraints",0x0ffbe1de,"Bullet.levelConstraints","Bullet.hx",28,0xb42ce59c)
		HX_STACK_THIS(this)
		struct _Function_1_1{
			inline static bool Block( hx::ObjectPtr< ::Bullet_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Bullet.hx",28,0xb42ce59c)
				{
					HX_STACK_LINE(28)
					Float _g = ::Reg_obj::state->level->get_width();		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(28)
					Float _g1 = __this->get_width();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(28)
					Float _g2 = (_g - _g1);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(28)
					return (__this->x > _g2);
				}
				return null();
			}
		};
		HX_STACK_LINE(28)
		if (((  ((!(((this->x < (int)0))))) ? bool(_Function_1_1::Block(this)) : bool(true) ))){
			HX_STACK_LINE(28)
			this->kill();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Bullet_obj,levelConstraints,(void))


Bullet_obj::Bullet_obj()
{
}

Dynamic Bullet_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_velocity") ) { return _velocity; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"levelConstraints") ) { return levelConstraints_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bullet_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_velocity") ) { _velocity=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bullet_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_velocity"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Bullet_obj,_velocity),HX_CSTRING("_velocity")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_velocity"),
	HX_CSTRING("update"),
	HX_CSTRING("levelConstraints"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bullet_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bullet_obj::__mClass,"__mClass");
};

#endif

Class Bullet_obj::__mClass;

void Bullet_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Bullet"), hx::TCanCast< Bullet_obj> ,sStaticFields,sMemberFields,
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

void Bullet_obj::__boot()
{
}

