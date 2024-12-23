//heimuya_jiaotu2.h ����ʹ��
//�ز� 2003��5��29

NPC_BEGIN(CNheimuya_jiaotu2);

virtual void create()
{
	set_name("����ʹ��",  "jiao tu" );

	set("gender", "����");
	set("attitude", "peaceful");
	set("icon",young_monk);

	create_family("�������", 6, "����");

	set("no_kill",1);
	set("age", random(20)+20);

	set("per", random(40));
    set("str", random(22)+12);
    set("int", random(22)+12);
    set("con", random(22)+12);
    set("dex", random(22)+12);
	
	set("max_hp", 6000+random(4000));
	set("hp", query("max_hp"));
	set("max_mp",  6000+random(4000));
    set("mp", query("max_mp"));
    
    set("mp_factor", 15+random(50));

    set("combat_exp", 1500000);
	set("score", 10000);

    set_skill("force", 180);             // �����ڹ�
    set_skill("hand", 180);					// ����ָ��
    set_skill("unarmed", 180);           // ����ȭ��
    set_skill("dodge", 180);             // ��������
	set_skill("sword", 180);             // ��������
    set_skill("parry", 180);             // �����м�
    set_skill("changquan", 180);         // ̫�泤ȭ
    set_skill("kuihua_xinfa", 180);      // �����ķ�
	set_skill("pixie_jian", 180);        // ��а����

    map_skill("force", "kuihua_xinfa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "pixie_jian");
	map_skill("sword", "pixie_jian");
    
    set("apply/armor", 100);
    set("apply/damage", 80);

	carry_object("changjian")->wield();
	
};

NPC_END;




