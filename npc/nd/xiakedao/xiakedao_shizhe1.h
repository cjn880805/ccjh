//shizhe1.h
//code by sound
//2001-07-10

NPC_BEGIN(CNxiakedao_shizhe1);

virtual void create()
{
	set_name("����1","shizhe");
	
	set("icon", waiter);
	set("gender", "����" );
	set("age", 14);
	set("long", "һ�����Ż��µĺ��ӡ�");
	set("shen_type", 1);
	set("combat_exp", 3000);
	set("str", 20);
	set("dex", 25);
	set("con", 20);
	set("int", 25);
	set("attitude", "friendly");
	create_family("���͵�", 2, "����");
	
	carry_object("cloth")->wear();
	
};

NPC_END;
