//CangBaoLin_yirenge.h ����ˮ��
//�ز� 2002.3.27

MF_BEGIN(CRCangBao_yirenge);

virtual void create()			
{
	set_name("����ˮ��");
	add_npc("pub_mengzeshizhe");
	add_door("����ɽ������","����ɽ������", "����ɽ����ˮ��");
	add_door("����ɽ�����","����ɽ�����", "����ɽ����ˮ��");
	set("monster_chance",60);
	set("mf/odds",60);		//	�������Ｘ��,����Ϊodds/100
	set("mf/count",1000);	//	��ϡ����������ʣ��ȼ�70����Ϊ��ϡ���,����Ϊ1/count
	set("mf/level",50);		//	��������ȼ���30-99Ϊ���,�ȼ�Ϊlevel
};

MF_END;




