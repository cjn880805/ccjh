//CangBaoLin_xiyanglou.h Ϧ��¥
//�ز� 2002.3.27

MF_BEGIN(CRCangBao_xiyanglou);

virtual void create()			
{
	set_name("Ϧ��¥");
	add_npc("pub_mengzeshizhe");
	add_door("����ɽɽ��","����ɽɽ��", "����ɽϦ��¥");
	add_door("����ɽ����","����ɽ����", "����ɽϦ��¥");
	add_door("����ɽ�ɴ��","����ɽ�ɴ��", "����ɽϦ��¥");
	set("monster_chance",60);
	set("mf/odds",70);		//	�������Ｘ��,����Ϊodds/100
	set("mf/count",1000);	//	��ϡ����������ʣ��ȼ�70����Ϊ��ϡ���,����Ϊ1/count
	set("mf/level",55);		//	��������ȼ���30-99Ϊ���,�ȼ�Ϊlevel
};

MF_END;




