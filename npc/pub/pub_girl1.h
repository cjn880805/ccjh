NPC_BEGIN(CNpub_girl1);

virtual void create()
{
	
	set_name("�Ϲ�����","girl");
	
	set("icon", young_woman3);
	set("gender", "Ů��" );
	set("age", 22);
	set("long", "�Ϲ��Ĵ�����Ĵ��е�����������ɽˮ�ķ��ϣ������Ц����������������������Ű�ɫ���£���ɫ�Ŀ�㣬�������ź�˿����ӣ�ͷ�ϲ��Ų�ɫ��ͷ��");
	set_temp("apply/defense", 7);
	set("combat_exp", 2000);
	set("shen_type", 1);
	set("per", 25);
	set("str", 24);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	
	carry_object("whitecloth1")->wear();
	
	add_money(50);
};



NPC_END;
