//CangBaoLin_mzeshanjiao.h ����ɽɽ��
//�ز� 2002.3.27

MF_BEGIN(CRCangBao_mzshanjiao);

virtual void create()			
{
	set_name("ɽ��");
	add_npc("pub_mengzeshizhe");
	add_door("����ɽ�����","����ɽ�����", "����ɽɽ��");
	add_door("����ɽϦ��¥","����ɽϦ��¥", "����ɽɽ��");
	set("monster_chance",50);
	set("mf/odds",70);		//	�������Ｘ��,����Ϊodds/100
	set("mf/count",1000);	//	��ϡ����������ʣ��ȼ�70����Ϊ��ϡ���,����Ϊ1/count
	set("mf/level",45);		//	��������ȼ���30-99Ϊ���,�ȼ�Ϊlevel
};

MF_END;




