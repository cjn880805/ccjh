//xiaoju.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_xiaoju);

virtual void create()
{
	set_name("С��","xiaoju");

	set("icon", young_woman2);
	set("long", "һ��ģ�����ɵ�СѾ��������������ɫ������ϸ��ʱ�������һ��С�롣");
	set("gender", "Ů��");
	set("age", 15);
	set("combat_exp", 1000);
    set_skill("dodge", 10);
    set_skill("unarmed", 10);
    set_temp("apply/attack",  10);
    set_temp("apply/defense", 10);
	set("shen_type", 1);

	add_money(1);
	carry_object("red_cloth")->wear();


};

NPC_END;
