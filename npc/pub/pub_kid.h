//kid.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_kid);

virtual void create()
{
	set_name("小孩","kid");
	
	set("icon", boy1);
    set("gender", "男性" );
    set("age", 7);
    set("long", "这是个维吾尔族小孩子");
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
