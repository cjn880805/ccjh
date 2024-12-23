//chufang.h

//Sample for room: 厨房
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "厨房");

	CBox * box = Add_Box();
	box->add_object("puercha", 1);	
	box->set_name( "铁柜");	

	add_door("大理城王府内厅", "大理城王府内厅", "大理城王府厨房");

	set("long", "这里是镇南王府的内厅。整个大厅十分宽阔。虽说是王府，但摆设很简单，正中间有两张太师椅，边上摆满了各种各样的山茶花。" );

};


ROOM_END;
