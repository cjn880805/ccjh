NPC_BEGIN(CNpub_guniang);

virtual void create()
{
	set_name("̨�Ĺ���","guniang");
	
	set("icon", young_woman9);
	set("gender", "Ů��" );
	set("age", 17);
	set("long", "һλ�����̨�Ĺ����������Ļ��Խ��´���ɫͲȹ��");
	set_temp("apply/defense", 5);
	set("combat_exp", 7000);
	set("shen_type", 1);
	set("per", 28);
	set("str", 14);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	carry_object("tongqun")->wear();
};

NPC_END;
