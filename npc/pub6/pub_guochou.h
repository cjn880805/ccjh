//pub_guochou.h
//wuqing 2002-2-10

NPC_BEGIN(CNpub_guochou);

virtual void create()
{    
    set_name("����", "guo chou");
    set("long","�����������⣬����һ��");	
    set("gender", "����"); 
    set("title","��������");
    set("age", 33);
    set("str", 40); 
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("per", 20);
    set("icon", young_man2);

    set("max_hp", 10000);
    set("mp", 6000);
    set("max_mp", 4000);
    set("mp_factor", 50); 
    set("combat_exp", 1200000); 
    set("score", 180000);

	set("chat_chance", 5);

    set_skill("force", 170);
    set_skill("beiming_shengong", 170);
    set_skill("dodge", 170);
    set_skill("guimei_shenfa", 170);
    set_skill("unarmed", 170);
    set_skill("liuyang_zhang", 170);
    set_skill("parry", 170);
    set_skill("club", 170);
    set_skill("zhanjiang_jue", 170);
    set_skill("zhemei_shou", 170);
    set_skill("hand", 170);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "guimei_shenfa");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "zhanjiang_jue");
    map_skill("club", "zhanjiang_jue");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 120);
    set("apply/damage", 60);
    carry_object("qimeigun")->wield();

}
virtual void die()
{
	message_vision("$HIR������ֵ��ǣ����ȳ�����", this);
	destruct(this);
}

char * chat_msg()
{
	message_vision("$N���������ڣ����ƻ��Ƶ�ԶԶ��ȥ��", this);
	DESTRUCT_OB(this, "pub_guochou::chat_msg");
	return 0;
}

NPC_END;




