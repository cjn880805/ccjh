NPC_BEGIN(CNpub_gongnu);

virtual void create()
{
	
	set_name("����ʹ���Ů","gongnu");
	

	set("icon", young_woman2);
	set("gender", "Ů��" );
	set("age", 17);
	set("long", "һλ����ʹ������幬Ů�������󷢣��̳�������һ��װ��Ŀ�ޱ��顣");
	set_temp("apply/defense", 5);
	set("combat_exp", 7000);
	set("shen_type", 1);
	set("per", 28);
	set("str", 14);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	carry_object("whitecloth1")->wear();
	
	
	
};



NPC_END;
