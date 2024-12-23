//skybook.h

//Sample for ITEM: 无字天书

ITEM_BEGIN(CIskybook);


virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("无字天书");	//set item name

 	set_weight(10);		//set item weight

	set("unit", "本");
 	set("long", "此乃当年仙人赠于“蛋生”的宝物,因为蛋生不识字,仙人施了法,把天书变成了无字天书,呵呵!就是文盲也能读懂,快看看(kan)吧！");
	set("material", "unknow");
 
    set("no_steal", 1);
    set("no_beg", 1);
//    set("no_drop","哇？天书都想丢掉,小心遭天谴。");

};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	char team[40];

	if(strcmp(comm, "study") == 0)
		return kan_book(me);
	if(strcmp(comm, "canwu") == 0)
	{
		analyse_string(arg, team, 40);
		return canwu_book(me,atoi(team));
	}
	return 0;
}

int kan_book(CChar *me)
{
	tell_object(me, "功能：使用参悟(canwu)命令来突破武功的极限，但必须耗费自身的武学经验才可以有所小成。");
	return 1;
}

int canwu_book(CChar * me,int exp)
{
//	char msg[255];
	say("为了门派间的平衡考虑，参悟功能需要等其他门派任务完成后再同时开放，敬请谅解。",me);
/*	say("欲参天书，先废读书。",me);
	say("废了读书，未必能悟。",me);
	say("若要参悟，再去读书。",me);
	say("读书、参悟，任君自悟。",me);
*/
	SendMenu(me);
//	int exp1=me->query("combat_exp")-CChar::Level2Exp(me->query("level"))-me->query("sk_exp");
	return 1;
}

/*
int cloud_goto(CChar * me, string id)
{
	MAP2USER * user;
	iterator_user p;
	CUser * obj;

	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		obj = p->second;
		if (obj->querystr("id")==id &&  !wizardp(obj))
		{
             tell_object(me,"你一个筋斗窜向空中,只见眼前红云飞过,耳边风呼呼作响 ..\n哇喔,好痛快,好爽,爽歪歪!\n你驾着云缓缓下降,叭叽一声,嘿!安全着陆...");
             me->move(obj->environment());
             return 1;
         }
    }
    
	return 0;
}
*/
virtual void owner_is_killed(CChar *me)
{
	if(me)
		tell_object(me,"只见眼前金光一闪...好象是.....");

	destruct(this);
}


ITEM_END;
//last, register the item into ../server/ItemSetup.cpp



