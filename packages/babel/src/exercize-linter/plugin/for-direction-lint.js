import {declare} from '@babel/helper-plugin-utils'

const forDirectionLint = declare((api, options) => {
    api.assertVersion(7)

    return {
        pre(file) {
            file.set('forDirection', [])
        },
        visitor:{
            ForStatement(path,state) {
                const errors = state.file.get('forDirection')
                const testOperator = path.node.test.operator
                const updateOperator = path.node.update.operator

                let sholdUpdateOperator;
                if(['<','<='].includes(testOperator)){
                    sholdUpdateOperator = '++'
                }else if(['>','>='].includes(testOperator)){
                    sholdUpdateOperator = '--'
                }

                if(sholdUpdateOperator !== updateOperator){
                    const tmp = Error.stackTraceLimit
                    Error.stackTraceLimit = 0
                    errors.push(path.get('update').buildCodeFrameError('for direction error',Error))
                    // errors.push(path.node)
                    Error.stackTraceLimit = tmp
                }
            }
        },
        post(file) {
            console.log(file.get('forDirection'))
        }
    }
})

export default forDirectionLint