//yinpanshui.h

//Sample for room: �ƺ�Ӫ��ˮ
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_yinpanshui);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�Ӫ��ˮ");
	
	add_npc("pub_jianke");      //add by zdn 2001-07-14


	add_door("�ƺӱ�����", "�ƺӱ�����", "�ƺ�Ӫ��ˮ");
	add_door("�ƺӹų���", "�ƺӹų���", "�ƺ�Ӫ��ˮ");

	set("long","�����ǵ��������޳���ʱפ���ĵط��������ξ��з������������Դ�����פ�����˺ü�����ˮ����ʹʿ���ǲ��ú��ֿ���ɬ����ˮ�������˵صİ����ǽ�����ΪӪ��ˮ��������ľ�Ϊ�����񾮡���");
	

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"bingcao",
		"northeast" : __DIR__"guchangcheng",
	]));
********************************************/
};


CHANGAN_END;
