NPC_BEGIN(CNPub_funu);

virtual void create()
{
	set_name("̨�ĸ�Ů","funu");

	set("icon", young_woman5);
    set("gender", "Ů��" );
    set("age", 37);
    set("long", "һλ�����̨�ĸ�Ů����������Ļ��Խ��´���ɫͲȹ�����ڱ�֯������");
 	set_temp("apply/defense", 5);
	set("combat_exp", 3000);
	set("shen_type", 1);
    set("per", 20);
    set("str", 24);
    set("dex", 25);
    set("con", 16);
    set("int", 15);
    set("attitude", "friendly");
    carry_object("tongqun")->wear();

	add_money(100);
};

NPC_END;
