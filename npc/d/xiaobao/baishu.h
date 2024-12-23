// baishu.h 小白鼠
// 秦波	2002、12、25

NPC_BEGIN(CNbaishu);

virtual void create()
{
	set_name("小白鼠","bai shu");
	set("icon", 49);

	set("race", "野兽");
	set("age", 2);
	set("long", "这是一只浑身雪白的小老鼠。");
	set("str", 20);
	set("cor", 20);
	
	CVector v;

	v.append("bite");
	set("verbs", v);

	set("combat_exp", 3000+random(5000));

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",15);
};

virtual int do_look(CChar * me)
{
	say("这是一只浑身雪白的小老鼠。", me);
	SendMenu(me);
	return 1;
}

NPC_END;




