//pub_henmantian.h
//wuqing 2002-2-10

NPC_BEGIN(CNpub_henmantian);

virtual void create()
{    
    set_name("������", "hen man tian");
    set("long","һ�������书����Ϊ��ȴа��");	
    set("gender", "����"); 
    set("title","�������");
    set("age", 33);
    set("str", 40); 
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("per", 30);
    set("icon", young_man2);

	set("hp", 10000);
	set("max_hp", 10000);
	set("mp", 8000);
	set("max_mp", 4000);
	set("mp_force", 50);
	set("combat_exp", 150000);
	set("score", 1600000);

    set_skill("force", 200);
    set_skill("beiming_shengong", 200);
    set_skill("dodge", 200);
    set_skill("guimei_shenfa", 200);
    set_skill("unarmed", 200);
    set_skill("liuyang_zhang", 200);
    set_skill("parry", 200);
    set_skill("club", 200);
    set_skill("zhanjiang_jue", 200);
    set_skill("zhemei_shou", 200);
    set_skill("hand", 200);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "guimei_shenfa");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "zhanjiang_jue");
    map_skill("club", "zhanjiang_jue");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 100);
    set("apply/damage", 50);
    carry_object("qimeigun")->wield();

	set("chat_chance", 5);

}
virtual void die()
{
	message_vision("$HIR������ֵ��ǣ����ȳ�����", this);
	destruct(this);
}

char * chat_msg()
{
	message_vision("$N���������ڣ����ƻ��Ƶ�ԶԶ��ȥ��", this);
	DESTRUCT_OB(this, "pub_henmantian::chat_msg");
	return 0;
}

NPC_END;



