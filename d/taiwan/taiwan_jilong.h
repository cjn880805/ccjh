//jilong.h
//Sample for room: ̨�弦����
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRTaiWan_jilong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̨�弦����");
	set("resident", "����");
	set("capacity", 5);
	
	add_npc("pub_yufu");       //add by zdn 2001-07-16
	add_npc("pub_liudingguo");
	add_door("̨��ĵ�", "̨��ĵ�", "̨�弦����");
	add_door("Ȫ�������", "Ȫ�������", "̨�弦����");

	set("long", "����Ϊ̨�山�����ۡ�Ⱥɽ�����ĸۿڸ��ع�����̳��ܣ��С�̨���������֮�Ƶĳ����������ڴ˿�����ɣ��������Ϣ���Ű�������  " );

};





RESIDENT_END;
