//pub_zangma.h ��������
//wjc 2002-02-24

NPC_BEGIN(CNpub_zangma);


virtual void create()
{
	set_name("����", "zang ma");
	set("nickname", "����");
	set("gender", "����");
	set("age", 20);
	set("long", "������������������ʿ���·���һ�����Ե����Ŀֲ�ɱ�֡�");
	
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",young_man4);			    //������������
	
	set("str", 35);
	set("int", 34);
	set("con", 35);
	set("dex", 40);
	
	set("chat_chance", 5);			    //�����Զ����촥����
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
	
	set("hp", 15000);
	set("max_hp", 15000);
	set("mp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 50);
	
	set("combat_exp", 1200000);
	set("score", 50000);

	set_skill("force", 170);			       // �����ڹ�
	set_skill("huntian_qigong", 170);          
	set_skill("whip", 170);			           // �����޷�
	set_skill("yunlong_bian", 170);		       // �����޷�
	set_skill("dodge", 170);			       // ��������
	set_skill("yunlong_shenfa", 170);	       // ������
	set_skill("parry", 170);			       // �����м�
	set_skill("unarmed", 170);
	set_skill("xianglong_zhang", 170);
	
	map_skill("force", "huntian_qigong");		
	map_skill("whip", "yunlong_bian");	        //����NPC�Ļ����޷�װ�������޷�
	map_skill("dodge", "yunlong_shenfa");		//����NPC�Ļ����Ṥװ��������
	map_skill("parry", "yunlong_bian");		    //����NPC�Ļ����м�װ�������޷�
	map_skill("unarmed", "xianglong_zhang");	//����NPC�Ļ���ȭ��װ��������

	prepare_skill("unarmed","xianglong_zhang");
	set("apply/armor", 100);
    set("apply/damage", 40);
	carry_object("changbian")->wield();
	
}


virtual char * chat_msg_combat()			    //NPC�Զ�������
{
	switch(random(5))
	{
	case 0:
		perform_action("whip chan", 1);	       //�����޷��Ĳ��־�
		break;
	case 1:
		perform_action("force recover", 0);	   //�Զ�����
		break;
	
	}	
	return 0;
}

virtual void die()
{
	message_vision("$HIR������ֵ��ǣ����ȳ�����", this);
	destruct(this);
}

char * chat_msg()
{
	message_vision("$N���������ڣ����ƻ��Ƶ�ԶԶ��ȥ��", this);
	DESTRUCT_OB(this, "pub_zangma::chat_msg");
	return 0;

}
NPC_END;




