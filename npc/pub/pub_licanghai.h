//pub_licanghai.h
//wuqing 2002-2-10

NPC_BEGIN(CNpub_licanghai);

virtual void create()
{    
    set_name("��׺�", "li cang hai");
    set("long","������һ��ħŮ���������������·�����Ůȴ�ĺ�����������");	
    set("gender", "Ů��"); 
    set("title","����ħŮ");
    set("age", 75);
    set("str", 40); 
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("per", 40);
    set("icon",young_woman5);

    set("max_hp", 25500);
    set("mp", 10000);
    set("max_mp", 10000);
    set("mp_factor", 100); 
    set("combat_exp", 3800000); 
    set("score", 200000);

    set_skill("force", 300);
    set_skill("beiming_shengong", 300);
    set_skill("dodge", 300);
    set_skill("lingboweibu", 300);
    set_skill("unarmed", 300);
    set_skill("liuyang_zhang", 300);
    set_skill("parry", 300);
    set_skill("blade", 300);
    set_skill("xiaoyao_dao", 300);
    set_skill("zhemei_shou", 300);
    set_skill("hand", 300);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "lingboweibu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "xiaoyao_dao");
    map_skill("blade", "xiaoyao_dao");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 300);
    set("apply/damage", 180);
    carry_object("gangdao")->wield();
	set("no_kill",1);//����������ٹȵ�������

}
virtual void die()
{
	message_vision("$HIR������ֵ��ǣ����ȳ�����", this);
	destruct(this);
}
NPC_END;




