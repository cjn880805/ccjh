//huangtianmen.h

//Sample for room:  �����»�����
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_huangtianmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����»�����");

				
	add_door("�������޳���", "�������޳���", "�����»�����");
	add_door("���������ָ�", "���������ָ�", "�����»�����");
	add_door("�������嶼��̨", "�������嶼��̨", "�����»�����");

	set("long","���ǳ���ǰ���µıؾ�֮·��������ȥ���ɼ�������̨ͤ¥���ģ��󣬹���������լ�����ƣ�������֮ʢ��ʤ����̨�����ӵ������ʤ�ص���ɽ���¡�");
    

/******************************************************************************
	set("outdoors","tianlongsi");
        set("exits", ([
		"south": __DIR__"yaotai",    			
	        "west" : __DIR__"wulege",
		"east" : __DIR__"wuchangge",
	]));
******************************************************************************/
};


ROOM_END;
