//cyjian.h	重阳剑
//秦波 2002、3、14

EQUIP_BEGIN(CIcyjian);

virtual void create(int nFlag = 0)		
{
	set_name( "重阳剑");	
	
	set("wield_position", WIELD_RIGHT_HAND);		
	set("skill_type", "sword");			
	set_weight(20000);		
	
	set("unit", "把");
	set("value", 8000);
	set("material", "steel");
	set("long", "这是全真教祖师重阳真人王重阳随身之物，当年伴王重阳抗击金兵，沙场杀敌不计其数。剑身已略微斑驳，血槽上亦留有拭之不去的暗红。现在已是全真教的镇教之宝。");
   	set("wield_msg","$N解开青布束缚着的$n，只见霎那间红光映面，冤戾冲天，非有重阳祖师的定力不能把持此剑。");
   	set("unwield_msg", "$N一抖剑身，用软纱小心的拂去上面的血迹，缓缓将$n包裹了起来。");
	set("apply/damage", 250+random(51));	
	set("duration", 100+random(50));
};


const char * hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	if(add("duration", -1) <= 0)
	{
		call_out(destruct_me, 1);
		return "$HIW$w在$n身上化成一道白光，消散不见了……$COM";
	}
	
	return 0;
}

virtual int Can_Equip(CChar * me)
{
	if(me->query_skill("taoism",1)<200)
	{
		say("你的道学心法等级不够，没有重阳祖师的定力，不能把持此剑。",me);
		SendMenu(me);
		return 0;
	}
	return 1;
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp



