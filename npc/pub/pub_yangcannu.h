//yangcannu.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_yangcannu);

virtual void create()
{
	set_name("����Ů","yangcannu");

	set("icon", young_woman10);
	set("gender", "Ů��" );
	set("age", 21);
	set("long", "һ������İ��Ĵ帾�����Ϸ�˿Ϊ����");
	set_temp("apply/defense", 5);
	set("combat_exp", 5000);
	set("shen_type", 1);
	set("per", 21);
	set("str", 14);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	
	carry_object("bduanqun")->wear();
	
};



NPC_END;
