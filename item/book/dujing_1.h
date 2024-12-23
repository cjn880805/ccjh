//dujing_1.h

//Sample for ITEM: 『星宿毒经〖上册〗』
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIdujing_1);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "『星宿毒经〖上册〗』");	//set item name

 	set_weight(10);		//set item weight

	set("unit", "张");
	set("long", "『星宿毒经〖上册〗』:　　毒经为星宿宝典，凡以此经及经内所载药物私与他人，即视为欺师灭祖、背叛师门。对叛师之徒，虽上天入地，吾弟子必予诛之。外人持有本经者，吾弟子见一个杀一个，见十个杀十个，断不容私阅本门宝典者苟存于世。　　　　　　　　　　　　　　　　　　　　　　　　　　星宿老仙　丁      【蒙汗药】　用法：将药倒入酒水中诱人喝下（pour yao in <容器>）。　药性：不致命，可使人昏厥。对内力极强者，药效不显。【春药】　用法：将药倒入酒水中诱人喝下（pour yao in <容器>）。　药性：不论男女，服后欲火如焚，可为我所用。【断肠散】　用法：将药倒入酒水中诱人喝下（pour yao in <容器>）。　药性：服药后肝肠寸断而亡。对内力强者，药效不显。【清心散】　用法：吞服（eat san）。　药性：为本门毒门解药，可解断肠散和星宿毒掌之毒。");
	set("value", 50);
	set("material", "paper");
	set("skill/name","poison");	// name of the skill
	set("skill/exp_required",50000);	// minimum combat experience required
	set("skill/jing_cost",20);	// jing cost every time study this
	set("skill/difficulty",25);	// the base int to learn this skill
	set("skill/max_skill",99);	// the maximum level you can learn
	set("skill/min_skill",50);  // the maximum level you can learn

 
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp