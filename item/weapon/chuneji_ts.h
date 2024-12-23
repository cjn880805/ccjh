//chunjie_ts.h 唐诗三百首
//秦波 2002-03-26

EQUIP_BEGIN(CIchunjie_ts);

virtual void create(int nFlag = 0)	
{
	set_name( "唐诗三百首");	

    set("wield_position", WIELD_LEFT_HAND);		//set the position of wield
	set_weight(1000);		//set item weight
	
	set("unit", "本");
	set("long", "一本凝聚唐代众多诗人名家心血之作的诗集，经常阅读，会使你的文学修为得到提升！");
	set("value", 1);
	set("apply/int",10);

};

virtual void owner_is_killed(CChar *me)
{
	if(me)
		tell_object(me,"只见眼前金光一闪...好象是.....");

	destruct(this);
} 

EQUIP_END;



