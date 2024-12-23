//heimuya_jiaotu1.h ����ʹ��
//�ز� 2002��4��25

NPC_BEGIN(CNheimuya_jiaotu1);

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
    set("str", random(20)+10);
    set("int", random(20)+10);
    set("con", random(20)+10);
    set("dex", random(20)+10);
	
	set("max_hp", 5000+random(3000));
	set("hp", query("max_hp"));
	set("max_mp",  5000+random(3000));
    set("mp", query("max_mp"));
    
    set("mp_factor", 10+random(50));

    set("combat_exp", 1000000);
	set("score", 10000);

    set_skill("force", 150);             // �����ڹ�
    set_skill("hand", 150);					// ����ָ��
    set_skill("unarmed", 150);           // ����ȭ��
    set_skill("dodge", 150);             // ��������
	set_skill("sword", 150);             // ��������
    set_skill("parry", 150);             // �����м�
    set_skill("changquan", 150);         // ̫�泤ȭ
    set_skill("kuihua_xinfa", 150);      // �����ķ�
	set_skill("pixie_jian", 150);        // ��а����

    map_skill("force", "kuihua_xinfa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "pixie_jian");
	map_skill("sword", "pixie_jian");
    
    set("apply/armor", 80);
    set("apply/damage", 60);
	
};

NPC_END;




