//pub_youzhu.h �ַ�����
//wjc 2002-02-24

NPC_BEGIN(CNpub_youzhu);


virtual void create()
{
	set_name("�ַ���", "you zhu");
	set("nickname", "����");
	set("gender", "����");
	set("age", 18);
	set("long", "��������������ԭ��ʿ����ֹ�ḡ��");
	
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",young_man3);			    //������������
	
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 45);
	
	set("chat_chance", 5);			    //�����Զ����촥����
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
	
	set("hp", 16000);
	set("max_hp", 16000);
	set("mp", 12000);
	set("max_mp", 6000);
	set("mp_factor", 50);
	
	set("combat_exp", 1200000);
	set("score", 55000);
	
	set_skill("force", 170);			    // �����ڹ�
	set_skill("kurong_shengong", 170);		// ������
	set_skill("finger", 170);			    // ����ָ��
	set_skill("sun_finger", 170);		    // ��Ʒһ��ָ
	set_skill("dodge", 170);			    // ��������
	set_skill("xiaoyaoyou", 170);			// ��ң��
	set_skill("parry", 170);			    // �����м�
	
	map_skill("force", "kurong_shengong");		//����NPC��ǰ�ڹ�Ϊ������
	map_skill("finger", "sun_finger");	        //����NPC�Ļ���ָ��װ����Ʒһ��ָ
	map_skill("dodge", "xiaoyaoyou");		    //����NPC�Ļ����Ṧװ����ң��
	map_skill("parry", "sun_finger");		    //����NPC�Ļ����м�װ����Ʒһ��ָ

	prepare_skill("finger", "sun_finger");
	set("apply/armor", 100);
    set("apply/damage", 60);

	
}

char * chat_msg()
{
	message_vision("$N���������ڣ����ƻ��Ƶ�ԶԶ��ȥ��", this);
	DESTRUCT_OB(this, "pub_youzhu::chat_msg");
	return 0;

}

virtual char * chat_msg_combat()			    //NPC�Զ�������
{
	switch(random(5))
	{
	case 0:
		perform_action("finger qiankun", 1);	//��Ʒһ��ָ�ľ���
		break;
	case 1:
		perform_action("force recover", 0);   	//�Զ�����
		break;
	
	}	
	return 0;
}
virtual void die()
{
	message_vision("$HIR������ֵ��ǣ����ȳ�����", this);
	destruct(this);
}
NPC_END;




