//CangBaoLin_elvxiaodao.h ����С��
//�ز� 2002.3.27

MF_BEGIN(CRCangBao_elvxiaodao);

virtual void create()			
{
	set_name("����С��");
	add_npc("pub_mengzeshizhe");
	add_door("����ɽ����֮��","����ɽ����֮��", "����ɽ����С��");
	add_door("����ɽ����","����ɽ����", "����ɽ����С��");
	set("monster_chance",60);
	set("mf/odds",70);		//	�������Ｘ��,����Ϊodds/100
	set("mf/count",1000);	//	��ϡ����������ʣ��ȼ�70����Ϊ��ϡ���,����Ϊ1/count
	set("mf/level",80);		//	��������ȼ���30-99Ϊ���,�ȼ�Ϊlevel
};

MF_END;




