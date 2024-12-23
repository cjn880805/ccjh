//GaoCang_mg_7.h 地狱第3层
//秦波 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_7);

virtual void create()			
{
	set_name("沸沙地狱");

	CDoor * a = add_yewaidoor("west", 8, 20);
	CDoor * b = add_yewaidoor("north", 8, 20);
	CDoor * c = add_yewaidoor("east", 8, 20);
	CDoor * d = add_yewaidoor("south", 8, 20);

	a->set_name("迷宫西");
	b->set_name("迷宫北");
	c->set_name("迷宫东");
	d->set_name("迷宫南");
	add_door("刀山地狱", "高昌刀山地狱", "高昌沸沙地狱");
	add_npc("dy_master");

	set("long", "多形巨石悬压头顶，使人深感此狱的压抑。远处，一坡坎上立着挂尸木架，架上吊着各种不同的残尸。中间区二鬼正拉锯分尸，岩边一鬼役满面狞笑，正操持圆盘锯将一受刑者送入利齿；另一岩石下，一独眼巨鬼操着大称称吊在阳世缺斤少两、坑害百姓的罪人（手足绑在一起），巨鬼的另一瞎眼伸出一长颈骷髅，监看称星受刑者的重量；近处，虎灶上大铁锅内沙泥被烧得滚烫，数鬼役将受刑者投入锅中炙炒，灶右侧一受刑者正被一鬼卒押跪在灶台上欲施沸沙之刑。 ");

};

virtual int do_look(CChar * me)
{
	say("多形巨石悬压头顶，使人深感此狱的压抑。远处，一坡坎上立着挂尸木架，架上吊着各种不同的残尸。中间区二鬼正拉锯分尸，岩边一鬼役满面狞笑，正操持圆盘锯将一受刑者送入利齿；另一岩石下，一独眼巨鬼操着大称称吊在阳世缺斤少两、坑害百姓的罪人（手足绑在一起），巨鬼的另一瞎眼伸出一长颈骷髅，监看称星受刑者的重量。", me);
	say("近处，虎灶上大铁锅内沙泥被烧得滚烫，数鬼役将受刑者投入锅中炙炒，灶右侧一受刑者正被一鬼卒押跪在灶台上欲施沸沙之刑。 ", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
