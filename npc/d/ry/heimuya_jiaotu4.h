//heimuya_jiaotu2.h ����ʹ��
//�ز� 2003��5��29

NPC_BEGIN(CNheimuya_jiaotu4);

virtual void create()
{
	set_name("����ʹ��",  "jiao tu" );

	set("gender", "����");
	set("attitude", "peaceful");
	set("icon",young_monk);

	create_family("�������", 4, "����");

	set("no_kill",1);
	set("age", random(20)+20);

	set("per", random(40));
    set("str", random(26)+17);
    set("int", random(26)+17);
    set("con", random(26)+17);
    set("dex", random(26)+17);
	
	set("max_hp", 13000+random(7000));
	set("hp", query("max_hp"));
	set("max_mp",  8000+random(4000));
    set("mp", query("max_mp"));
    
    set("mp_factor", 35+random(50));

    set("combat_exp", 2500000);
	set("score", 10000);

    set_skill("force", 250);             // �����ڹ�
    set_skill("hand", 250);					// ����ָ��
    set_skill("unarmed", 250);           // ����ȭ��
    set_skill("dodge", 250);             // ��������
	set_skill("blade", 250);             // ��������
    set_skill("parry", 250);             // �����м�
    set_skill("changquan", 250);         // ̫�泤ȭ
    set_skill("kuihua_xinfa", 250);      // �����ķ�
	set_skill("pixie_jian", 250);        // ��а����
	set_skill("jinwu_daofa", 250);       // ���ڵ�

    map_skill("force", "kuihua_xinfa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "shengji_blade");
	map_skill("blade", "jinwu_daofa");
    
    set("apply/armor", 110);
    set("apply/damage", 90);

	carry_object("gangdao")->wield();
	
};

NPC_END;




