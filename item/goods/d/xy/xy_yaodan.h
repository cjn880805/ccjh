//shen.h 逍遥任务特殊道具
ITEM_BEGIN(CIxy_yaodan)

virtual void create(int nFlag = 0)		
{
	set_name("药单", "yao dan");
	set("long",	"无根水、雪水、露水、三七、乌鸡、珍珠、白芷、菊花、白果、红枣、杏仁、白附子、密陀僧、胡粉、白羊髓、白藓、酒、鸡蛋、浮萍、桃花、荷花、荷叶、芙蓉花、苍术、白及、秦艽、白薇、牡丹、冰台、人参、蒲公英、川芎、薄荷、百合、稻禾、稻米。");
	set("unit", "张");
	set_weight(10);
	set("value", 1);
};

ITEM_END;




