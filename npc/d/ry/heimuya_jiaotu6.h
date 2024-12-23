//heimuya_jiaotu6.h ����ʹ��
//�ز� 2003��5��29

NPC_BEGIN(CNheimuya_jiaotu6);

virtual void create()
{
	set_name("����ʹ��",  "jiao tu" );

	set("gender", "����");
	set("attitude", "peaceful");
	set("icon",young_monk);

	create_family("�������", 3, "����");

	set("no_kill",1);
	set("age", random(20)+20);

	set("per", random(40));
    set("str", random(29)+19);
    set("int", random(29)+19);
    set("con", random(29)+19);
    set("dex", random(29)+19);
	
	set("max_hp", 18000+random(7000));
	set("hp", query("max_hp"));
	set("max_mp",  10000+random(4000));
    set("mp", query("max_mp"));
    
    set("mp_factor", 50+random(50));

    set("combat_exp", 3500000);
	set("score", 10000);

    set_skill("force", 300);             // �����ڹ�
    set_skill("hand", 300);					// ����ָ��
    set_skill("strike", 300);           // ����ȭ��
    set_skill("dodge", 180);             // ��������
	set_skill("jinshe_zhang", 300);             // ����������
    set_skill("parry", 300);             // �����м�
    set_skill("kuihua_xinfa", 300);      // �����ķ�
	set_skill("pixie_jian", 300);        // ��а����

    map_skill("force", "kuihua_xinfa");
    map_skill("strike", "jinshe_zhang");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "jinshe_zhang");

	prepare_skill("strike", "jinshe_zhang");
    
    set("apply/armor", 140);
    set("apply/damage", 110);
	set("chat_chance_combat", 15);
	
};

virtual char * chat_msg_combat()
{
	perform_action("strike fugu", 1);
	return "";
}
NPC_END;




