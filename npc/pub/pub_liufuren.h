//liufuren.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_liufuren);

virtual void create()
{
	set_name("������","liufuren");
	
	set("icon", young_woman2);
	set("gender", "Ů��");
	set("long", "���������ķ��ˡ�");
	set("age", 42);
	set("attitude", "peaceful");
	set("per", 23);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	
	carry_object("cloth")->wear();
	
};

NPC_END;
