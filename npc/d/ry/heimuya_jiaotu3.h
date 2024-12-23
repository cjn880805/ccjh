//heimuya_jiaotu2.h ����ʹ��
//�ز� 2003��5��29

NPC_BEGIN(CNheimuya_jiaotu3);

virtual void create()
{
	set_name("����ʹ��",  "jiao tu" );

	set("gender", "����");
	set("attitude", "peaceful");
	set("icon",young_monk);

	create_family("�������", 5, "����");

	set("no_kill",1);
	set("age", random(20)+20);

	set("per", random(40));
    set("str", random(25)+15);
    set("int", random(25)+15);
    set("con", random(25)+15);
    set("dex", random(25)+15);
	
	set("max_hp", 10000+random(6000));
	set("hp", query("max_hp"));
	set("max_mp",  7000+random(6000));
    set("mp", query("max_mp"));
    
    set("mp_factor", 30+random(50));

    set("combat_exp", 2000000);
	set("score", 10000);

    set_skill("force", 220);             // �����ڹ�
    set_skill("unarmed", 220);           // ����ȭ��
    set_skill("dodge", 220);             // ��������
	set_skill("club", 220);             // ��������
    set_skill("parry", 220);             // �����м�
    set_skill("changquan", 220);         // ̫�泤ȭ
    set_skill("kuihua_xinfa", 220);      // �����ķ�
	set_skill("pixie_jian", 220);        // ��а����
	set_skill("duanhun_qiang", 220);       // �ϻ�ǹ��

    map_skill("force", "kuihua_xinfa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "duanhun_qiang");
	map_skill("club", "duanhun_qiang");
    
    set("apply/armor", 120);
    set("apply/damage", 100);

	carry_object("changqiang")->wield();
	
};

NPC_END;




