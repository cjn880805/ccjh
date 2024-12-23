//pub_huanhai.h �ú�
//wjc 2002-02-24

NPC_BEGIN(CNpub_huanhai);


virtual void create()
{
	set_name("�ú�", "huan hai");
	set("gender", "Ů��");
	set("age", 60);
	set("long", "��С����������������ϵ�Ť��������һ������񹦣�������ʱ���ܿ����Լ��ľ�ֹ��");
	
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",old_woman);			    //������������
	
	set("str", 25);
	set("int", 35);
	set("con", 35);
	set("dex", 40);
	
	set("chat_chance", 5);			    //�����Զ����촥����
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
	
	set("hp", 15000);
	set("max_hp", 15000);
	set("mp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 50);
	
	set("combat_exp", 1300000);
	set("score", 50000);
	
	set_skill("force", 170);			        // �����ڹ�
	set_skill("xuantian_shengong", 170);		// ������
	set_skill("finger", 170);			        // ����ָ��
	set_skill("sun_finger", 170);		        // ��Ʒһ��ָ
	set_skill("dodge", 170);			        // ��������
	set_skill("lingboweibu", 170);		    	// �貨΢��
	set_skill("parry", 170);			        // �����м�
	
	map_skill("force", "xuantian_shengong");		//����NPC��ǰ�ڹ�Ϊ������
	map_skill("finger", "sun_finger");	            //����NPC�Ļ���ָ��װ����Ʒһ��ָ
	map_skill("dodge", "lingboweibu");		        //����NPC�Ļ����Ṧװ���貨΢��
	map_skill("parry", "sun_finger");		        //����NPC�Ļ����м�װ����Ʒһ��ָ
	
	prepare_skill("finger", "sun_finger");
	set("apply/armor", 100);
    set("apply/damage", 40);
}


virtual char * chat_msg_combat()			        //NPC�Զ�������
{
	switch(random(5))
	{
	case 0:
		perform_action("finger qiankun", 1);	    //��Ʒһ��ָ�ľ���
		break;
	case 1:
		perform_action("force recover", 0);	        //�Զ�����
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
	DESTRUCT_OB(this, "pub_huanhai::chat_msg");
	return 0;
}

NPC_END;




