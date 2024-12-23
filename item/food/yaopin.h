//yaopin.h
//自动合并的药品
//Lanwood 2001-02-13

#define YAOPIN_BEGIN(item_name)	class item_name : public CIyaopin	{	public:	item_name(){};	virtual ~item_name(){};
#define YAOPIN_END		};

FOOD_BEGIN(CIyaopin);

//重载Move，到非Room中可自动合并
virtual int move(CContainer *pMe)
{
	DTItemList search;
	CContainer * env, * t;
	POSITION p;
	LONG	total;
	const char * id;
	int index;
	
	if(! CItem::move(pMe)) return 0;	//未移动成功。

	if((env = environment()))
	{
		if(env->Query(IS_ROOM)) return 1;

		CopyList(&search, env->Get_ItemList());
		id = querystr("base_name");
		index = query("index");
		total = Query_Amount();
		p = search.GetHeadPosition();
		while(p)
		{
			t = search.GetNext(p);
			if( t == this ) continue;
			if( ! t->Query(IS_ITEM) ) continue;
			if( EQUALSTR(t->querystr("base_name"), id)	&& t->query("index") == index) 
			{
				total += ((CItem *)t)->Query_Amount();
				destruct(t);
		    }
		 }
		if(query("base_weight"))
			set_weight(query("base_weight")*total);
	     set_amount(total);
	}

	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp