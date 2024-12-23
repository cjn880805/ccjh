//gueiyun.h



//Sample for room  ����ׯ

//coded by zwb

//data: 2000-11-17



//Note: these two headers must be include

//use macro ROOM_BEGIN(room_name) to declare room

//and use macro ROOM_END end declare

ROOM_BEGIN(CRGueiYuncity);



//room_name must use "CR-" begin since it belongs room class

//Example: Xiang Yang City named "CRXiangYangCity"



//under, we will custom our room



virtual void create()			//Call it when Room Create

{
	//set name of our room

	set_name( "����ׯ");

	add_npc("taohua_lu");
	add_npc("guiyun_dabei"); 
	add_npc("guiyun_fanyifei");
	add_npc("guiyun_fengliang");  
	add_npc("guiyun_gaosan");      //add by zdn 2001-07-20

	add_door("�����Ϻ�", "�����Ϻ�", "����ׯ");
	add_door("����ׯ����", "����ׯ����", "����ׯ");
	add_door("����ׯ�鷿", "����ׯ�鷿", "����ׯ");
	add_door("����ׯŮ�᷿", "����ׯŮ�᷿", "����ׯ");
	add_door("����ׯ������", "����ׯ������", "����ׯ");
	add_door("����ׯ���᷿", "����ׯ���᷿", "����ׯ");
};





ROOM_END;
