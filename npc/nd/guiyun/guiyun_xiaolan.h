// xiaolan.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_xiaolan);

virtual void create()
{
	set_name("С��", "xiao lan");
	set("long", "һ��ģ�����ɵ�СѾ�����������������۾����ģ����ǳǳһ�Ծ��ѡ�");
	set("gender", "Ů��");
	set("age", 15);
	set("icon", girl2);
	set("combat_exp", 1000);
        set_skill("dodge", 10);
        set_skill("unarmed", 10);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
	set("shen_type", 1);

	add_money(100);
//	carry_object("red_cloth")->wear();
}

NPC_END;