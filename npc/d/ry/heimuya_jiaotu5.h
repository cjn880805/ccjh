//heimuya_jiaotu5.h ����ʹ��
//�ز� 2003��5��29

NPC_BEGIN(CNheimuya_jiaotu5);

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
    set("str", random(28)+18);
    set("int", random(28)+18);
    set("con", random(28)+18);
    set("dex", random(28)+18);
	
	set("max_hp", 16000+random(8000));
	set("hp", query("max_hp"));
	set("max_mp",  9000+random(4000));
    set("mp", query("max_mp"));
    
    set("mp_factor", 45+random(50));

    set("combat_exp", 3000000);
	set("score", 10000);

    set_skill("force", 280);             // �����ڹ�
    set_skill("hand", 280);					// ����ָ��
    set_skill("unarmed", 280);           // ����ȭ��
    set_skill("dodge", 280);             // ��������
	set_skill("whip", 280);             // ��������
    set_skill("parry", 280);             // �����м�
    set_skill("changquan", 280);         // ̫�泤ȭ
    set_skill("kuihua_xinfa", 280);      // �����ķ�
	set_skill("pixie_jian", 280);        // ��а����
	set_skill("wudu_bian", 280);        // �嶾�޷�
	set_skill("wudu_xinfa", 280);        // �嶾�ķ�

    map_skill("force", "kuihua_xinfa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "changquan");
	map_skill("whip", "wudu_bian");
    
    set("apply/armor", 120);
    set("apply/damage",100);

	carry_object("changbian")->wield();
	set("chat_chance_combat", 15);
	
};

virtual char * chat_msg_combat()
{
	perform_action("whip judu", 1);
	return "";
}

NPC_END;




