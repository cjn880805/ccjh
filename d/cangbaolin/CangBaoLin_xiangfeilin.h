//CangBaoLin_xiangfeilin.h ������
//�ز� 2002.3.27

MF_BEGIN(CRCangBao_xiangfeilin);

virtual void create()			
{
	set_name("������");
	add_npc("pub_mengzeshizhe");
	add_door("����ɽ����","����ɽ����", "����ɽ������");
	add_door("����ɽ����ˮ��","����ɽ����ˮ��", "����ɽ������");
	set("monster_chance",60);
	set("mf/odds",70);		//	�������Ｘ��,����Ϊodds/100
	set("mf/count",1000);	//	��ϡ����������ʣ��ȼ�70����Ϊ��ϡ���,����Ϊ1/count
	set("mf/level",60);		//	��������ȼ���30-99Ϊ���,�ȼ�Ϊlevel
};

MF_END;




