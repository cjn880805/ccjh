//hengshan_yafu.h
//code by sound
//2001-07-11

NPC_BEGIN(CNhengshan_yafu);

virtual void create()
{
	set_name("�Ƹ�", "yafu");
        set("gender", "Ů��" );
        set("age", 37);
        set("long", "���Ǹ����겻���ڵ��Ƹ�");
        set("combat_exp", 50000);
	set("shen_type", 0l);
	set("str", 21);
	set("per", 20);
	set("dex", 21);
	set("con", 21);
	set("int", 21);
 	set("icon",old_woman);
        set("attitude", "friendly");
        
	carry_object("cloth")->wear();
}

NPC_END;