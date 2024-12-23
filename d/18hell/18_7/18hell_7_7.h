//18hell_7.h
//十八地狱第三层沸沙地狱第7房间

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_7_7);

virtual void create()			//Call it when Room Create
{
	set_name("沸沙地狱");
	set("long", "多形巨石悬压头顶，使人深感此狱的压抑。远处，一坡坎上立着挂尸木架，架上吊着各种不同的残尸。中间区二鬼正拉锯分尸，岩边一鬼役满面狞笑，正操持圆盘锯将一受刑者送入利齿；另一岩石下，一独眼巨鬼操着大称称吊在阳世缺斤少两、坑害百姓的罪人（手足绑在一起），巨鬼的另一瞎眼伸出一长颈骷髅，监看称星受刑者的重量；近处，虎灶上大铁锅内沙泥被烧得滚烫，数鬼役将受刑者投入锅中炙炒，灶右侧一受刑者正被一鬼卒押跪在灶台上欲施沸沙之刑。 ");
	
	add_npc("diyu_shizhe7");

};

virtual int do_look(CChar * me)
{
	say("多形巨石悬压头顶，使人深感此狱的压抑。远处，一坡坎上立着挂尸木架，架上吊着各种不同的残尸。中间区二鬼正拉锯分尸，岩边一鬼役满面狞笑，正操持圆盘锯将一受刑者送入利齿；另一岩石下，一独眼巨鬼操着大称称吊在阳世缺斤少两、坑害百姓的罪人（手足绑在一起），巨鬼的另一瞎眼伸出一长颈骷髅，监看称星受刑者的重量。", me);
	say("近处，虎灶上大铁锅内沙泥被烧得滚烫，数鬼役将受刑者投入锅中炙炒，灶右侧一受刑者正被一鬼卒押跪在灶台上欲施沸沙之刑。 ", me);
	SendMenu(me);
	return 1;
}

ROOM_END;
