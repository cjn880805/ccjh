//zhongxiaoer.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_zhongxiaoer);

virtual void create()
{
	set_name("��С��","zhongxiaoer");
	
	set("icon", boy1);
	set("gender", "����" );
	set("age", 3);
	set("long", "�����Ӱ��ĵĶ����ӣ���ֻ�ǹ���׷��˺ҧ����");
	set("combat_exp", 50);
	set("shen_type", 1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
	set("attitude", "friendly");
	
	carry_object("cloth")->wear();
};


NPC_END;
