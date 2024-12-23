//biaoqi.h 镖旗
//秦波 2002、2、15

ITEM_BEGIN(CIbiaoqi)

void create(int nFlag = 0)	
{
	set_name("镖旗", "biaoqi");
    set("value", 1);      
	set("long",	"这是福威镖局的一面镖旗，江湖上的黑、白道朋友见了它都会给上几分面子。");
	set("unit", "面");
	set_weight(10);
	set("material", "paper");
}

ITEM_END;




