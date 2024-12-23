// guojing.c ����
//sound 2001-07-11

NPC_BEGIN(CNxiangyang_guojing);

virtual void create()
{
	set_name("�����", "guo jing");
	set("nickname", "����");
	set("gender", "����");
	set("age", 41);
	set("long", 
		"�������˳Ʊ����ľ���磬�����ɹųɼ�˼���Ľ��������ǽ����߹֡�ȫ�������ڵ���������ؤ���͡�����ͯ�����˵�ͽ�ܣ���������书��������һ����ɫ���ۣ���̬���࣬�غ����Ŀ��͸��һ�����ϡ�");
	
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",young_man4);			//������������
	
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 25);
	
	set("chat_chance", 1);			//�����Զ����촥����
	set("chat_chance_combat", 20);		//����NPCʹ�þ��еļ���
	
	set_inquiry("�ܲ�ͨ", "��������ܴ���ˣ������ڿɺã�");
	set_inquiry("����ͯ", "�ܴ��һ��������û��������");
	set_inquiry("��л�", "ʦ�����˳ԣ�����ϲ���档�����棬����Ϊ���ҳԵġ�");
	set_inquiry("���Ϲ�", "������̩ɽ���ˡ��������ĺ����������ײ���β�ġ�");
	set_inquiry("���ƴ�ʦ", "���¶Դ�ʦ�����м���");
	set_inquiry("����ׯ��", "����϶����������λʦ����һ���������ˣ������������ݡ�");
/*	set_inquiry("����", "�ض����ҵİ��ޣ�������������");*/
	set_inquiry("�ض�", "�ض������ض��ˡ�������ô����");
	set_inquiry("ܽ��", "���Ů�����ֱ��ֲ�������");
	set_inquiry("���", "��������������Ⱳ���ֶ��򡣵�Ը���ܿ���һ����");
	set_inquiry("��²��", "�����ҵ�С���ӡ�");
	set_inquiry("����", "����ȷʵ�г�Ϣ��");
	set_inquiry("����", "����������а�ʦ֮�ꡣ");	
	set_inquiry("���ڻ�", "������屡���죬������ܡ�");
	set_inquiry("�±�а", "�����Ҵ�ʦ����");
	set_inquiry("����", "�����Ҷ�ʦ����");
	set_inquiry("������", "��������ʦ����");
	set_inquiry("������", "��������ʦ����");
	set_inquiry("����", "��������ʦ����");
	set_inquiry("ȫ����", "��������ʦ����");	
	set_inquiry("��С��", "��������ʦ����");
	set_inquiry("ؤ��", "ؤ��Ӣ�ۼ������ˣ�����������������ǡ�");
	set_inquiry("��ʦ", "�����ɹ���Χ��������������������ͽ����");
//	"job"   : (: ask_job :),
//	"����"  : (: ask_gonglao :),
//	"fangqi": (: ask_fangqi :),
//	"����"  : (: ask_fangqi :),
//	"��ϸ"  : (: ask_jianxi :),
	
	
	set("hp", 20000);
	set("max_hp", 20000);
	set("mp", 12000);
	set("max_mp", 12000);
	set("mp_factor", 500);
	
	set("combat_exp", 15000000);
	set("score", 500000);

	set("����/gaibang/wuhui",1);
	set("family/family_name","ؤ��");
	set("death_times",99);
	
	set_skill("force", 280);			// �����ڹ�
	set_skill("huntian_qigong", 280);		// ��������
	set_skill("unarmed", 280);			// ����ȭ��
	set_skill("xianglong_zhang", 280);		// ����ʮ����
	set_skill("dodge", 200);			// ��������
	set_skill("xiaoyaoyou", 200);			// ��ң��
	set_skill("parry", 280);			// �����м�
	
	map_skill("force", "huntian_qigong");		//����NPC��ǰ�ڹ�Ϊ��������
	map_skill("unarmed", "xianglong_zhang");	//����NPC�Ļ���ȭ��װ��������
	map_skill("dodge", "xiaoyaoyou");		//����NPC�Ļ����Ṥװ����ң��
	map_skill("parry", "xianglong_zhang");		//����NPC�Ļ����м�װ��������
	set("no_huan",1);
}

virtual char * chat_msg()				//NPC�Զ�����
{
	switch(random(2))
	{
	case 0:
		return 	"����̾�˿����������ɹű��ù��������£�һ�����ٳ���ƣ��ض��ֲ�����ߣ���....��";
	case 1:
		return 	"����˵���������ݹ���������֪�ɺã����һ��Ҫ�ش�Įȥ����������";
	}	
	return 0;
}

virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(3))
	{
	case 0:
		perform_action("unarmed xianglong", 1);	//�����Ƶľ���
		break;
	case 1:
		perform_action("force recover", 0);	//�Զ�����
		break;
	case 2:
		perform_action("unarmed wuhuei", 1);	//�����Ƶľ���
		break;
	}	
	return 0;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "�ر�ͼ") && EQUALSTR(ob->querystr("base_name"), "cang bao tu") )
	{
		if(me->query("xkd/lingjiu") && me->query("xkd/gumu") && me->query("xkd/mingjiao") && me->query("xkd/ry")
			&& me->query("xkd/huashan") )
		{
			//��ʼ���ԣ���ʤ������Ի��ȥ���͵����ʸ�Ŀǰ��ʱ������
			tell_object(me, "\n$HIC����˵���������Ʒ������ȷ���������Ҫ���õ��Ļ������ó��㱾�¸��ҿ�������");
			destruct(ob);
			return 1;
		}
		else
			tell_object(me, "\n$HIC����˵������ƾ�����ڵĽ�����������û���ʸ�������̸�������");
	}
	return 0;
}

NPC_END;
