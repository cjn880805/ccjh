//bingcao.h

//Sample for room: �ƺӱ�����
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_bingcao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺӱ�����");
	
	add_npc("huanghe_liang");    //add by zdn 2001-07-14
	
	add_npc("pub_diaoer");
	add_npc("pub_gousan");
	add_npc("pub_guyi");
	

	add_door("�ƺ�ʯϿ��", "�ƺ�ʯϿ��", "�ƺӱ�����");
	add_door("�ƺ�Ӫ��ˮ", "�ƺ�Ӫ��ˮ", "�ƺӱ�����");

	set("long","��������Ӫ��ˮ�����ϣ�ƽʱ�˼���������Ϊ����ɳĮ�ﳤ��һ�������ҩ��----'����'����������˵����ҩ���ܽ�ٶ�������ż�����������ֲݣ�����ɳĮ�ﳣ�ж����û����ΪΣ�ա�");

};


CHANGAN_END;
