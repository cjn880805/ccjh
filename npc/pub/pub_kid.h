//kid.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_kid);

virtual void create()
{
	set_name("С��","kid");
	
	set("icon", boy1);
    set("gender", "����" );
    set("age", 7);
    set("long", "���Ǹ�ά�����С����");
    set("combat_exp", 50);
	set("shen_type", 1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
    set("attitude", "friendly");
	carry_object("wcloth")->wear();

};


NPC_END;
