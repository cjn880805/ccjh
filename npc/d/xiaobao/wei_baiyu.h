//wei_baiyu.h 白鱼
//小宝任务

NPC_BEGIN(CNwei_baiyu);

virtual void create()
{
	set_name("白鱼","bai yu");

    set("long", "太湖特有的鱼种，通体洁白如玉，样子非常可爱。");

    set("race", "野兽");
    set("age", 3);
    set("attitude", "peaceful");

    set("max_hp", 10000);
    set("str", 40);
    set("cor", 50);

	CVector v;

	v.append("bite");
	set("verbs", v);

    set_temp("apply/attack", 100);
    set_temp("apply/damage", 100);
    set_temp("apply/armor", 100);
	set_temp("apply/dodge", 200);

    set("combat_exp", 100000);
	if(random(2))
		carry_object("baiyupi");

	set("no_kill",1);
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

NPC_END;
