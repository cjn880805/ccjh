//CangBaoLin_huanshagu.h �ɴ��
//�ز� 2002.3.27

MF_BEGIN(CRCangBao_huanshagu);

virtual void create()			
{
	set_name("�ɴ��");
	add_npc("pub_mengzeshizhe");
	add_door("����ɽϦ��¥","����ɽϦ��¥", "����ɽ�ɴ��");
	add_door("����ɽ���¶�","����ɽ���¶�", "����ɽ�ɴ��");
	add_door("����ɽ����֮��","����ɽ����֮��", "����ɽ�ɴ��");
	set("monster_chance",60);
	set("mf/odds",70);		//	�������Ｘ��,����Ϊodds/100
	set("mf/count",1000);	//	��ϡ����������ʣ��ȼ�70����Ϊ��ϡ���,����Ϊ1/count
	set("mf/level",75);		//	��������ȼ���30-99Ϊ���,�ȼ�Ϊlevel
};

MF_END;




